/*
 * effect.cpp
 *
 *  Created on: 24 mar 2018
 *      Author: SF
 */

#include "effect.hpp"

const std::list<std::shared_ptr<IFX>> *FXList::getCurrentFXList(){
	return &actualFX;
}

std::list<std::shared_ptr<IFX>>  *FXList::getFXList(){
	return &futureFX;
}

void FXList::updateFX(){
	actualFX = futureFX;
}

