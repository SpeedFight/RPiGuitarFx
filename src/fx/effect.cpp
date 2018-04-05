/*
 * effect.cpp
 *
 *  Created on: 24 mar 2018
 *      Author: SF
 */

#include "effect.hpp"

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

/*
 * Setting
 */

Setting::Setting(std::string newName, int *controllerValue, int initValue, int newMaxValue, int newMinValue ):
		name(newName),
		valueFromController(controllerValue),
		value(initValue),
		maxValue(newMaxValue),
		minValue(newMinValue){


}

std::string *Setting::getName(){
	return &name;
}

void Setting::update(){

	value += *valueFromController;
	valueFromController = 0;

	if(value < minValue){
		value = minValue;
	}else if(value > maxValue){
		value = maxValue;
	}
}

int Setting::getValue(){
	return value;
}
