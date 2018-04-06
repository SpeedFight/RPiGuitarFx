/*
 * effect.cpp
 *
 *  Created on: 24 mar 2018
 *      Author: SF
 */

#include "effect.hpp"

/*
 * Setting
 */

Setting::Setting(std::string newName, int *controllerValue, int initValue, int newMinValue, int newMaxValue ):
		name(newName),
		valueFromController(controllerValue),
		actualValue(initValue),
		maxValue(newMaxValue),
		minValue(newMinValue){

}

std::string *Setting::getName(){
	return &name;
}

void Setting::updatePotentiometers(){
	actualValue += *valueFromController;
	*valueFromController = 0;

	if(actualValue < minValue){
		actualValue = minValue;
	}else if(actualValue > maxValue){
		actualValue = maxValue;
	}

}

int Setting::getValue(){
	return actualValue;
}

/*
 * IFX
 */

IFX::IFX(IDetector *newUserInput):
		userInput(newUserInput)
		{

}

void IFX::updateSettings(){
	for(auto &controller : settings){
		controller.updatePotentiometers();
	}
}


/*
 * FXList
 */

FXList::FXList()
		{
	futureFX.reserve(DEFAULT_RESERVED_FX_LIST_SIZE);
	actualFX.reserve(DEFAULT_RESERVED_FX_LIST_SIZE);
}

const std::vector<std::shared_ptr<IFX>> *FXList::getCurrentFXList(){
	return &actualFX;
}

std::vector<std::shared_ptr<IFX>>  *FXList::getFXList(){
	return &futureFX;
}

void FXList::updateFX(){
	actualFX = futureFX;
}


