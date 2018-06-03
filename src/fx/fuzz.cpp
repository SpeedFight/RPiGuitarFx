/*
 * simpleOverdriveFX.cpp
 *
 *  Created on: 5 kwi 2018
 *      Author: SF
 */

#include <fuzz.hpp>

const std::string Fuzz::nameFx("Fuzz");

void Fuzz::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){
	float gain = settings.at(0).getValue()*1.5;
	float bias = settings.at(1).getValue()/11.00;
	float mix = settings.at(2).getValue()/20.0;

	auto upsampledInput = upSampler->up(inBufs);


	for(unsigned int i = 0; i < nframes * 4; ++i){
		float q = ((upsampledInput[0][i]+ bias) * gain);
		float sign;
			if (q > 0){
				sign = 1;
			}else{
				sign = -1;
			}
			upsampledInput[0][i] = sign * (1-exp(-std::abs(q))) * 0.98;
	}

	upSampler->down(outBufs);

	for(unsigned int i = 0; i <= nframes; ++i){
		outBufs[0][i] = outBufs[0][i] * mix + inBufs[0][i] * (1.0 - mix);
	}
}

Fuzz::Fuzz(IDetector *newUserInput):
		IFX(newUserInput),
		upSampler(new UpDownSample(audioSettings::x4, audioSettings::buffSize))
		{
	settings = std::vector<Setting>{
		Setting("gain", userInput->getInputHandler(ControllerInput::pot2), 2, 1, 25),
		Setting("bias", userInput->getInputHandler(ControllerInput::pot3), 0, 0, 10),
		Setting("mix", userInput->getInputHandler(ControllerInput::pot4), 20, 0, 20)
	};
}

Fuzz::~Fuzz(){
}

const std::string *Fuzz::getName(){
	return &Fuzz::nameFx;
}

std::vector<Setting> *Fuzz::getSettings(){

}



