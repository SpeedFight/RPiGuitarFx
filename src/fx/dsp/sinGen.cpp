/*
 * sinGen.cpp
 *
 *  Created on: 1 cze 2018
 *      Author: SF
 */

#include "sinGen.hpp"

SinGen::SinGen():
frequency(1),
phase(0),
phaseDiff(0),
output(0),
freqencyPeriod(1)
{

}

void SinGen::setToStart(float newFrequency, float newPhase){
	frequency = newFrequency;
	phase = newPhase;

	phaseDiff = 1.0/audioSettings::fs;
	freqencyPeriod = 1.0/frequency;

}

void SinGen::changeFrequency(float newFrequency){
	frequency = newFrequency;
}

float SinGen::getSample(){
	static float pi2 = 2 * M_PI;
	output = sinf(pi2 * phase * frequency);

	phase += phaseDiff;
	if (phase >= freqencyPeriod){
		phase = 0;
	}

	return output;
}

SinGen::~SinGen(){

}
