/*
 * simpleOverdriveFX.cpp
 *
 *  Created on: 5 kwi 2018
 *      Author: SF
 */

#include "simpleOverdriveFX.hpp"

const std::string SimpleOverdriveFx::nameFx("Simple overdrive");

	void SimpleOverdriveFx::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){
		for(unsigned int i = 0; i <= nframes; ++i){
			float q = inBufs[0][i] * settings[ControllerInput::pot1].getValue();

				float sign;
					if (q > 0){
						sign = 1;
					}else{
						sign = 0;
					}

					outBufs[0][i] = sign * (1-exp(-abs(q)))/1.5;
		}
		std::cout<<"wartosc pot1: "<<settings[ControllerInput::pot1].getValue()<<std::endl;

	}

	SimpleOverdriveFx::SimpleOverdriveFx(IDetector *newUserInput):
			IFX(newUserInput)
			{
		settings = std::vector<Setting>{Setting("gain", userInput->getInputHandler(ControllerInput::pot1), 10, 1, 300)};
	}

	SimpleOverdriveFx::~SimpleOverdriveFx(){
	}

	const std::string *SimpleOverdriveFx::getName(){
		return &SimpleOverdriveFx::nameFx;
	}

	std::vector<Setting> *SimpleOverdriveFx::getSettings(){

	}



