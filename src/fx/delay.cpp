/*
 * delay.cpp
 *
 *  Created on: 31 maj 2018
 *      Author: SF
 */

#include "delay.hpp"

const std::string Delay::nameFx("Simple overdrive");

void Delay::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){

	float BL, FF, FB;


	float time = settings.at(0).getValue();
	float time100 = settings.at(1).getValue();
	float duration = settings.at(2).getValue();

	for(unsigned int i = 0; i <= nframes; ++i){
		float q = inBufs[0][i] * pot2;
		float sign;
			if (q > 0){
				sign = 1;
			}else{
				sign = -1;
			}
		outBufs[0][i] = sign * (1-exp(-std::abs(q)));
	}
}

Delay::Delay(IDetector *newUserInput):
		IFX(newUserInput)
		{
	settings = std::vector<Setting>{
		Setting("time [ms]", userInput->getInputHandler(ControllerInput::pot2), 0, 0, 100),
		Setting("100 x time [ms]", userInput->getInputHandler(ControllerInput::pot3), 0, 2, 20),
		Setting("duration", userInput->getInputHandler(ControllerInput::pot4), 5, 0, 10)};
}

Delay::~Delay(){
}

const std::string *Delay::getName(){
	return &Delay::nameFx;
}

std::vector<Setting> *Delay::getSettings(){

}



