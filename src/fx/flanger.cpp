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
	static float FB = 0.7;


	float BL = settings.at(0).getValue()/20.0;
	float time = settings.at(1).getValue()/10000.0; //delay time in s, 0.0001 -> 0.002 s
	float depth = settings.at(2).getValue()/10000.0; //depth time in s 0.0001 -> 0.001 s
	float frequency = settings.at(3).getValue()/20.0; // 0.05 - 1 Hz

	float meanDelayTimeInSamples = time * (float)audioSettings::fs;
	float maxVariationDelayTimeInSamples = depth * (float)audioSettings::fs;

	sinGen->changeFrequency(frequency);

	for(unsigned int i = 0; i <= nframes; ++i){
		std::cout<<"meanDelayTimeInSamples "<<meanDelayTimeInSamples<<std::endl;
		std::cout<<"maxVariationDelayTimeInSamples "<<maxVariationDelayTimeInSamples<<std::endl;
		float tmp = sinGen->getSample();
		std::cout<<"sinGen "<<tmp<<std::endl;

		float delay = *delayLine->getPreviousFract(meanDelayTimeInSamples + maxVariationDelayTimeInSamples * tmp);
		float xh;
		xh = inBufs[0][i] + FB * delay;
		delayLine->toBuffer(xh);
		outBufs[0][i] = FF * delay + BL * xh;
		outBufs[0][i] = tmp;
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
		Setting("mix", userInput->getInputHandler(ControllerInput::pot2), 14, 0, 20),
		Setting("mean delay x10 us", userInput->getInputHandler(ControllerInput::pot3), 3, 0, 20), //max 2ms
		Setting("depth x10 us", userInput->getInputHandler(ControllerInput::pot4), 10, 1, 10), //max +/-1ms
		Setting("frequency x0.5 Hz", userInput->getInputHandler(ControllerInput::pot6), 5, 1, 20)// max 1Hz
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


