/*
 * triangleGen.cpp
 *
 *  Created on: 1 cze 2018
 *      Author: SF
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

	diff = 4/audioSettings::fs * frequency;

}

void TriangleGen::changeFrequency(float newFrequency){
	frequency = newFrequency;

	diff = 4/audioSettings::fs * frequency;
}

float TriangleGen::getSample(){

	output = output + diff;
	if (output >= 1){
	    diff = -diff;
	   	output += diff;
	}else if (output <= -1){
	    diff = -diff;
	   output += diff;
	}
	return output;
}

TriangleGen::~TriangleGen(){

}

