/*
 * flanger.cpp
 *
 *  Created on: 1 cze 2018
 *      Author: SF
 */

#include "flanger.hpp"

const std::string Flanger::nameFx("Flanger");

void Flanger::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){
	float set1 = settings.at(0).getValue();
	float set2 = settings.at(1).getValue();
	float set4 = settings.at(2).getValue();




	for(unsigned int i = 0; i <= nframes; ++i){
		outBufs[0][i] = inBufs[0][i];
	}

}
//max delay 2**11 samples
//if fs = 44100, then this time is 0.046 ms
//if fs = 48000, then this time is 0.042 ms
Flanger::Flanger(IDetector *newUserInput):
		IFX(newUserInput),
		delayLine(new DelayLine(11)),
		sinGen(new SinGen())
		{
	settings = std::vector<Setting>{
		Setting("mix", userInput->getInputHandler(ControllerInput::pot2), 10, 0, 20),
		Setting("delay x10 us", userInput->getInputHandler(ControllerInput::pot3), 0, 0, 20), //max 2ms
		Setting("depth x10 us", userInput->getInputHandler(ControllerInput::pot4), 10, 0, 20), //max 2ms
		Setting("frequency x0.5 Hz", userInput->getInputHandler(ControllerInput::pot6), 1, 0, 20)// max 1Hz


	};
}

Flanger::~Flanger(){
}

const std::string *Flanger::getName(){
	return &Flanger::nameFx;
}

std::vector<Setting> *Flanger::getSettings(){

}


