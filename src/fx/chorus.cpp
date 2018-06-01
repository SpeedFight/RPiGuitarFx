/*
 * chorus.cpp
 *
 *  Created on: 1 cze 2018
 *      Author: SF
 */

#include "chorus.hpp"

const std::string Chorus::nameFx("Chorus");

void Chorus::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){

	static float FF = 0.97;
	static float FB = -0.7;

	float BL = 1.0 - (settings.at(0).getValue()/20.0);
	float time = settings.at(1).getValue()/1000.0; //delay time in s, 0.001 -> 0.005 s
	float depth = settings.at(2).getValue()/2000.0; //depth time in s 0.0001 -> 0.005 s
	float frequency = settings.at(3).getValue()/10.0; // 0.05 - 1 Hz

	float meanDelayTimeInSamples = time * (float)audioSettings::fs;
	float maxVariationDelayTimeInSamples = depth * (float)audioSettings::fs;

	if (meanDelayTimeInSamples - maxVariationDelayTimeInSamples < 0){
		maxVariationDelayTimeInSamples = meanDelayTimeInSamples - 2;
	}

	triangleGen1->changeFrequency(frequency);

	for(unsigned int i = 0; i <= nframes; ++i){
//		std::cout<<"meanDelayTimeInSamples "<<meanDelayTimeInSamples<<std::endl;
//		std::cout<<"maxVariationDelayTimeInSamples "<<maxVariationDelayTimeInSamples<<std::endl;
//		std::cout<<"sinGen "<<tmp<<std::endl;
		float xh;

		float delay1 = *delayLine->getPreviousFract(meanDelayTimeInSamples + maxVariationDelayTimeInSamples * triangleGen1->getSample()) * 0.30;
		float delay2 = *delayLine->getPreviousFract(meanDelayTimeInSamples + maxVariationDelayTimeInSamples * triangleGen2->getSample()) * 0.30;
		float delay3 = *delayLine->getPreviousFract(meanDelayTimeInSamples + maxVariationDelayTimeInSamples * triangleGen3->getSample()) * 0.30;
//		float delay3 = 0;
		float delay = (delay1 + delay2 + delay3);
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
Chorus::Chorus(IDetector *newUserInput):
		IFX(newUserInput),
		delayLine(new DelayLine(13)),
		triangleGen1(new SinGen()),
		triangleGen2(new SinGen()),
		triangleGen3(new TriangleGen())
		{
	settings = std::vector<Setting>{
		Setting("mix", userInput->getInputHandler(ControllerInput::pot2), 17, 0, 20),
		Setting("mean delay x10 us", userInput->getInputHandler(ControllerInput::pot3), 10, 2, 50), //max 5ms
		Setting("depth x10 us", userInput->getInputHandler(ControllerInput::pot4), 5, 1, 50), //max +/-4ms>?
		Setting("frequency x0.1 Hz", userInput->getInputHandler(ControllerInput::pot6), 24, 1, 100)// max 10Hz
	};

	triangleGen1->setToStart(0.25, 0);
	triangleGen2->setToStart(0.25, -3);
	triangleGen3->setToStart(0.25, 1.4);
}

Chorus::~Chorus(){
}

const std::string *Chorus::getName(){
	return &Chorus::nameFx;
}

std::vector<Setting> *Chorus::getSettings(){

}
