/*
 * exampleFx.cpp
 *
 *  Created on: 11 maj 2018
 *      Author: SF
 */

#include "exampleFx.hpp"

const std::string ExampleFx::nameFx("Example");

void ExampleFx::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){
	float set1 = settings.at(0).getValue();
	float set2 = settings.at(1).getValue();
	float set4 = settings.at(2).getValue();

	for(unsigned int i = 0; i <= nframes; ++i){
		outBufs[0][i] = inBufs[0][i];
	}

}

ExampleFx::ExampleFx(IDetector *newUserInput):
		IFX(newUserInput)
		{
	settings = std::vector<Setting>{
		Setting("setting 1", userInput->getInputHandler(ControllerInput::pot2), 50, 0, 100),
		Setting("setting 1", userInput->getInputHandler(ControllerInput::pot3), 50, 0, 100),
		Setting("setting 1", userInput->getInputHandler(ControllerInput::pot4), 50, 0, 100)};
}

ExampleFx::~ExampleFx(){
}

const std::string *ExampleFx::getName(){
	return &ExampleFx::nameFx;
}

std::vector<Setting> *ExampleFx::getSettings(){

}
