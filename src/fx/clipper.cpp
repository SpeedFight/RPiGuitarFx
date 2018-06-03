/*
 * tube.cpp
 *
 *  Created on: 2 cze 2018
 *      Author: SF
 */

#include <clipper.hpp>

const std::string Clipper::nameFx("Clipper");

void Clipper::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){

	float gain = settings.at(0).getValue();
	float threshold = settings.at(1).getValue()/10.0;
	float Q = settings.at(2).getValue()/10.0;
	float character = settings.at(3).getValue()/10.0;
	float mix = settings.at(4).getValue()/20.0;

		auto upsampledInput = upSampler->up(inBufs);

		for(unsigned int i = 0; i < nframes * 4; ++i){
			upsampledInput[0][i] = (upsampledInput[0][i] + Q) * gain;

			float absVal = abs(upsampledInput[0][i]);
			if (absVal < threshold){
				upsampledInput[0][i] = 2.0 * upsampledInput[0][i];
			} else if (absVal >= threshold){
				if(upsampledInput[0][i] > 0){
					upsampledInput[0][i] = (3.0-powf( 2.0-upsampledInput[0][i]*3.0 , 2.0))/3.0;
					}else{
						upsampledInput[0][i] = -(3.0-powf(2.0-absVal*3, 2.0))/character;
					}
			} else if (absVal > 2 * threshold){
				if(upsampledInput[0][i] > 0){
					upsampledInput[0][i] = 1.0;
				}else{
					upsampledInput[0][i] = -1.0;
				}
			}
		}

		upSampler->down(outBufs);

		for(unsigned int i = 0; i <= nframes; ++i){
			outBufs[0][i] = outBufs[0][i] * mix + inBufs[0][i] * (1.0 - mix);
		}

}

Clipper::Clipper(IDetector *newUserInput):
		IFX(newUserInput),
		upSampler(new UpDownSample(audioSettings::x4, audioSettings::buffSize))
		{
	settings = std::vector<Setting>{
		Setting("gain", userInput->getInputHandler(ControllerInput::pot2), 5, 1, 50),
		Setting("threshold", userInput->getInputHandler(ControllerInput::pot3), 3, 1, 10),
		Setting("bias", userInput->getInputHandler(ControllerInput::pot4), 0, -10, 10),
		Setting("character", userInput->getInputHandler(ControllerInput::pot6), 3, 1, 10),
		Setting("mix", userInput->getInputHandler(ControllerInput::pot7), 20, 1, 20)
	};
}

Clipper::~Clipper(){
}

const std::string *Clipper::getName(){
	return &Clipper::nameFx;
}

std::vector<Setting> *Clipper::getSettings(){

}



