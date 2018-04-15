/*
 * dummyController.cpp
 *
 *  Created on: 15 kwi 2018
 *      Author: SF
 */

#include "dummyController.hpp"

DummyController::DummyController(int argc, char * argv[]){
	controllerValues.fill(0);
}

void DummyController::pollForEvents(void) {}

int *DummyController::getInputHandler(ControllerInput controllerInput){
	return &controllerValues[controllerInput];
}

