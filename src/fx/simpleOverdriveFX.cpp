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
			float q = inBufs[0][i] * 2.0;

				float sign;
					if (q > 0){
						sign = 1;
					}else{
						sign = 0;
					}

					outBufs[0][i] = sign * (1-exp(-abs(q)));
		}

	}

	SimpleOverdriveFx::SimpleOverdriveFx(){

	}

	SimpleOverdriveFx::~SimpleOverdriveFx(){
		settings.fill(0);
	}

	const std::string *SimpleOverdriveFx::getName(){

	}

	void SimpleOverdriveFx::setSettings(int *settings){

	}

	int *SimpleOverdriveFx::getSettings(){

	}


