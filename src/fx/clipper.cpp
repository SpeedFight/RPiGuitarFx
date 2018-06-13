/*
 * tube.cpp
 *
 *  Created on: 2 cze 2018
 *      Author: SF
 */

/*
RPiGuitarFx
Copyright (C) 2018  SpeedFight

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <clipper.hpp>

const std::string Clipper::nameFx("Clipper");

void Clipper::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){

	static float th = 0.3333333333333;

	float gain = settings.at(0).getValue();
	float Q = settings.at(1).getValue()/10.0;
	float mix = settings.at(2).getValue()/20.0;

#ifdef __arm__
	for(unsigned int i = 0; i < nframes; ++i){
		outBufs[0][i] = (outBufs[0][i] + Q) * gain;

		float absVal = std::abs(outBufs[0][i]);
		if (absVal < th){
			outBufs[0][i] = 2.0 * outBufs[0][i];
		} else if (absVal >= th){
			if(outBufs[0][i] > 0){
				outBufs[0][i] = (3.0-powf( 2.0-outBufs[0][i]*3.0 , 2.0))/3.0;
				}else{
					outBufs[0][i] = -(3.0-powf(2.0-absVal*3, 2.0))/3.0;
				}
		} else if (absVal > 2 * th){
			if(outBufs[0][i] > 0){
				outBufs[0][i] = 0.99;
			}else{
				outBufs[0][i] = -0.99;
			}
		}
	}
#else
	auto upsampledInput = upSampler->up(inBufs);

	for(unsigned int i = 0; i < nframes * 4; ++i){
		upsampledInput[0][i] = (upsampledInput[0][i] + Q) * gain;

		float absVal = std::abs(upsampledInput[0][i]);
		if (absVal < th){
			upsampledInput[0][i] = 2.0 * upsampledInput[0][i];
		} else if (absVal >= th){
			if(upsampledInput[0][i] > 0){
				upsampledInput[0][i] = (3.0-powf( 2.0-upsampledInput[0][i]*3.0 , 2.0))/3.0;
				}else{
					upsampledInput[0][i] = -(3.0-powf(2.0-absVal*3, 2.0))/3.0;
				}
		} else if (absVal > 2 * th){
			if(upsampledInput[0][i] > 0){
				upsampledInput[0][i] = 0.99;
			}else{
				upsampledInput[0][i] = -0.99;
			}
		}
	}

	upSampler->down(outBufs);
#endif

		for(unsigned int i = 0; i <= nframes; ++i){
			outBufs[0][i] = outBufs[0][i] * mix + inBufs[0][i] * (1.0 - mix);
		}

}

Clipper::Clipper(IDetector *newUserInput):
		IFX(newUserInput)
#ifndef __arm__
		,
		upSampler(new UpDownSample(audioSettings::x4, audioSettings::buffSize))
#endif
		{
	settings = std::vector<Setting>{
		Setting("gain", userInput->getInputHandler(ControllerInput::pot2), 5, 1, 50),
		Setting("bias", userInput->getInputHandler(ControllerInput::pot3), 0, 0, 10),
		Setting("mix", userInput->getInputHandler(ControllerInput::pot4), 20, 1, 20)
	};
}

Clipper::~Clipper(){
}

const std::string *Clipper::getName(){
	return &Clipper::nameFx;
}

std::vector<Setting> *Clipper::getSettings(){

}



