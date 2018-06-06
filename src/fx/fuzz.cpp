/*
 * simpleOverdriveFX.cpp
 *
 *  Created on: 5 kwi 2018
 *      Author: SF
 */

#include <fuzz.hpp>

const std::string Fuzz::nameFx("Fuzz");

float diodeClipper(float x, float y){
	static float R = 1.2e3;
	static float C = 0.1e-6;
	static float tau = R * C; //C * R
	static float Is = 10e-12;
	static float Vt = 14e-3;

	return (-1.0/tau * (y + x) - 2.0 * Is/C * std::sinh(y/Vt));

	//diode clipper test
//	static float lastOut;
//	static float dt = 1.0/audioSettings::fs;
//
//		for(unsigned int i = 0; i < nframes; ++i){
//
//			lastOut = lastOut + diodeClipper(inBufs[0][i] * gain, lastOut) * dt;
//			outBufs[0][i] = lastOut;
//			if(lastOut > 1){
//				lastOut = 0;
//				outBufs[0][i] = 0;
//			} else if (lastOut < -1){
//				lastOut = 0;
//				outBufs[0][i] = 0;
//			}
//		}

}


void Fuzz::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){
	float gain = settings.at(0).getValue()*1.5;
	float bias = settings.at(1).getValue()/11.00;
	float mix = settings.at(2).getValue()/20.0;


#ifdef __arm__
	for(unsigned int i = 0; i < nframes ; ++i){
			float q = ((inBufs[0][i]+ bias) * gain);
			float sign;
				if (q > 0){
					sign = 1;
				}else{
					sign = -1;
				}
				outBufs[0][i] = sign * (1-exp(-std::abs(q))) * 0.98;
		}
#else
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
#endif


	for(unsigned int i = 0; i <= nframes; ++i){
		outBufs[0][i] = outBufs[0][i] * mix + inBufs[0][i] * (1.0 - mix);
	}
}

Fuzz::Fuzz(IDetector *newUserInput):
		IFX(newUserInput)
#ifndef __arm__
		,
		upSampler(new UpDownSample(audioSettings::x4, audioSettings::buffSize))
#endif
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



