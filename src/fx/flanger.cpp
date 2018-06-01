/*
 * flanger.cpp
 *
 *  Created on: 1 cze 2018
 *      Author: SF
 */

#include "flanger.hpp"

const std::string Flanger::nameFx("Flanger");

void Flanger::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){

	static float FF = 0.7;
	static float FB = -0.7;

	float BL = (1.0 - settings.at(0).getValue()/20.0);
	float time = settings.at(1).getValue()/10000.0; //delay time in s, 0.0001 -> 0.005 s
	float depth = settings.at(2).getValue()/10000.0; //depth time in s 0.0001 -> 0.005 s
	float frequency = settings.at(3).getValue()/10.0; // 0.05 - 1 Hz

	float meanDelayTimeInSamples = time * (float)audioSettings::fs;
	float maxVariationDelayTimeInSamples = depth * (float)audioSettings::fs;

	if (meanDelayTimeInSamples - maxVariationDelayTimeInSamples < 0){
		maxVariationDelayTimeInSamples = meanDelayTimeInSamples - 2;
	}

	sinGen->changeFrequency(frequency);

	for(unsigned int i = 0; i <= nframes; ++i){
//		std::cout<<"meanDelayTimeInSamples "<<meanDelayTimeInSamples<<std::endl;
//		std::cout<<"maxVariationDelayTimeInSamples "<<maxVariationDelayTimeInSamples<<std::endl;
//		std::cout<<"sinGen "<<tmp<<std::endl;

		float delay = *delayLine->getPreviousFract(meanDelayTimeInSamples + maxVariationDelayTimeInSamples * sinGen->getSample());
		float xh;
		xh = inBufs[0][i]+ FB * delay;
		delayLine->toBuffer(xh);
		outBufs[0][i] = FF * delay + BL * xh * 0.98;
	}

}
//max delay 2**11 samples
//if fs = 44100, then this time is 0.046 s
//if fs = 48000, then this time is 0.042 s
//max delay 2**12 samples
//if fs = 44100, then this time is 0.092 s
//if fs = 48000, then this time is 0.085 s
Flanger::Flanger(IDetector *newUserInput):
		IFX(newUserInput),
		delayLine(new DelayLine(15)),
		sinGen(new SinGen())
		{
	settings = std::vector<Setting>{
		Setting("mix", userInput->getInputHandler(ControllerInput::pot2), 14, 0, 20),
		Setting("mean delay x10 us", userInput->getInputHandler(ControllerInput::pot3), 3, 2, 50), //max 5ms
		Setting("depth x10 us", userInput->getInputHandler(ControllerInput::pot4), 2, 1, 40), //max +/-4ms
		Setting("frequency x0.1 Hz", userInput->getInputHandler(ControllerInput::pot6), 5, 1, 50)// max 2Hz
	};

	sinGen->setToStart(0.25, 0);
}

Flanger::~Flanger(){
}

const std::string *Flanger::getName(){
	return &Flanger::nameFx;
}

std::vector<Setting> *Flanger::getSettings(){

}


