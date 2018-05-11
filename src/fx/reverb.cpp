/*
 * reverb.cpp
 *
 *  Created on: 11 maj 2018
 *      Author: SF
 */

#include "reverb.hpp"

const std::string Reverb::nameFx("Reverb");

void Reverb::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){
	float set1 = settings.at(0).getValue();
	float set2 = settings.at(1).getValue();
	float set4 = settings.at(2).getValue();

	for(unsigned int i = 0; i <= nframes; ++i){
		outBufs[0][i] = inBufs[0][i];
	}

}

Reverb::Reverb(IDetector *newUserInput):
		IFX(newUserInput)
		{
	settings = std::vector<Setting>{
		Setting("setting 1", userInput->getInputHandler(ControllerInput::pot2), 50, 0, 100),
		Setting("setting 1", userInput->getInputHandler(ControllerInput::pot3), 50, 0, 100),
		Setting("setting 1", userInput->getInputHandler(ControllerInput::pot4), 50, 0, 100)};
}

Reverb::~Reverb(){
}

const std::string *Reverb::getName(){
	return &Reverb::nameFx;
}

std::vector<Setting> *Reverb::getSettings(){

}
