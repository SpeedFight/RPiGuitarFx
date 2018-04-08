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

void FXList::moveFx(int fxToMoveIndex,int destinationIndex){

	if(fxToMoveIndex < 0){
		//TODO error handling
		return;
	}

	if(destinationIndex < 0){
		destinationIndex = 0;
	}

	if( destinationIndex > fxToMoveIndex){
		destinationIndex++;
		/*
		 * moveFx(0,1) dont move 0element to 1 position,
		 * moveFx(0,2) move o lement to 1 position
		 * add 1 to destinationIndex change a bit this logic
		 * so moveFx(0,1) work at it should at this situation
		 */
		if(destinationIndex > futureFX.size()){
			destinationIndex = futureFX.size();
		}
	}
	futureFX.insert(futureFX.begin()+destinationIndex, futureFX.at(fxToMoveIndex));

	if(fxToMoveIndex >= destinationIndex){
		fxToMoveIndex++; //compensate index
	}
	futureFX.erase(futureFX.begin()+fxToMoveIndex);
}

void FXList::removeFx(unsigned int fxToRemoveIndex){
	futureFX.erase(futureFX.begin()+fxToRemoveIndex);
}


