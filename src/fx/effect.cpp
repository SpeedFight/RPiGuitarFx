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

void Setting::update(){
	std::cout<<"update przed pobraniem wsk"<<std::endl;
	actualValue += *valueFromController;
	*valueFromController = 0;
	std::cout<<"update po pobraniu wsk"<<std::endl;

	if(actualValue < minValue){
		actualValue = minValue;
	}else if(actualValue > maxValue){
		actualValue = maxValue;
	}

	//std::cout<<"wartosc aktualna: "<<actualValue<<" wartośc z ptr do controlera"<<*valueFromController<<std::endl;
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
		controller.update();
	}
}


/*
 * FXList
 */
const std::list<std::shared_ptr<IFX>> *FXList::getCurrentFXList(){
	return &actualFX;
}

std::list<std::shared_ptr<IFX>>  *FXList::getFXList(){
	return &futureFX;
}

void FXList::updateFX(){
	actualFX = futureFX;
}


