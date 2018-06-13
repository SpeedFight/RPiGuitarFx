/*
 * triangleGen.cpp
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

#include "triangleGen.hpp"

TriangleGen::TriangleGen():
frequency(1),
phase(0),
diff(0),
output(0)
{

}

void TriangleGen::setToStart(float newFrequency, float newPhase){
	frequency = newFrequency;
	phase = newPhase;
	output = newPhase;

	diff = 4.0/audioSettings::fs * frequency;

}

void TriangleGen::changeFrequency(float newFrequency){
	frequency = newFrequency;

	diff = 4/audioSettings::fs * frequency;
}

float TriangleGen::getSample(){

	output += diff;
	if (output >= 1.0){
	    diff = -diff;
	   	output += diff;
	}else if (output <= -1.0){
	    diff = -diff;
	   output += diff;
	}
	return output;
}

TriangleGen::~TriangleGen(){

}

