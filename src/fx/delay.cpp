/*
 * delay.cpp
 *
 *  Created on: 31 maj 2018
 *      Author: SF
 */

#include "delay.hpp"

const std::string Delay::nameFx("Delay");

void Delay::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){
//	static float BL, FF, FB;
//	static float BL = 1;
//	FF =
//  FB =


//	static float yhold;
//	static float xhold;
//	static float b_0 = 0.5;
//	static float b_1 = 0.5;
//	static float a_1 = 0.7;

	float time = settings.at(0).getValue();
	float time100 = settings.at(1).getValue();
	float BL = settings.at(2).getValue()/20.0;
	float FF = settings.at(3).getValue()/20.0;
	float FB = settings.at(4).getValue()/20.0;
	bool loop = settings.at(5).getValue();

	unsigned int delayTimeInSamples = (((float)time + (float)time100 * 100.0)/1000.0) * (float)audioSettings::fs;

	for(unsigned int i = 0; i <= nframes; ++i){
		float delay = *delayLine->getPrevious(delayTimeInSamples);
		float xh;

//		xh = inBufs[0][i] + (FB * delay * b_0 * + b_1 * xhold - a_1 * yhold ); //filter
//		xhold = delay;
//		yhold = FF * delay + BL * xh;
//		outBufs[0][i] = yhold;

		xh = inBufs[0][i] + FB * delay; //no filter

		if(!loop){ //no loop
			xh = inBufs[0][i] + FB * delay; //no filter
			delayLine->toBuffer(xh);
		}else{ //loop, input not added to delay line
			xh = inBufs[0][i] + FB * delay; //no filter
			delayLine->toBuffer(FB * delay);
		}

		outBufs[0][i] = FF * delay + BL * xh;

	}
	std::cout<<"end"<<std::endl;
}

//max delay 2**17 samples
//if fs = 44100, then this time is 2.97s
//if fs = 48000, then this time is 2.73s
//max delay 2**18 samples
//if fs = 44100, then this time is 5.9s
//if fs = 48000, then this time is 5.43s
//max delay 2**19 samples
//if fs = 44100, then this time is 11.8s
//if fs = 48000, then this time is 10.9s

Delay::Delay(IDetector *newUserInput):
		IFX(newUserInput),
		delayLine(new DelayLine(18))
		{
	settings = std::vector<Setting>{
		Setting("time ms", userInput->getInputHandler(ControllerInput::pot2), 1, 1, 100),
		Setting("100x time ms", userInput->getInputHandler(ControllerInput::pot3), 4, 0, 50),
		Setting("mix", userInput->getInputHandler(ControllerInput::pot4), 10, 0, 20),
		Setting("intense", userInput->getInputHandler(ControllerInput::pot6), 5, 0, 20),
		Setting("feedback", userInput->getInputHandler(ControllerInput::pot7), 5, 0, 20),
		Setting("looper", userInput->getInputHandler(ControllerInput::pot8), 0, 0, 1)};



}

Delay::~Delay(){
}

const std::string *Delay::getName(){
	return &Delay::nameFx;
}

std::vector<Setting> *Delay::getSettings(){

}



