/*
 * sinGen.cpp
 *
 *  Created on: 1 cze 2018
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
	freqencyPeriod = 1.0/frequency;
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
