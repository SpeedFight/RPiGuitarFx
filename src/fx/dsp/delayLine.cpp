/*
 * delayLine.cpp
 *
 *  Created on: 31 maj 2018
 *      Author: SF
 */

#include "delayLine.hpp"

DelayLine::DelayLine(unsigned int powerOfTwoSize):
maxIndex(powf(2, powerOfTwoSize) - 1),
currentIndex(0)
{
	ringBuffer.reserve(maxIndex);
	std::fill(ringBuffer.begin(), ringBuffer.end(), 0.0);
}
void DelayLine::toBuffer(float newSample){
	ringBuffer[currentIndex] = newSample;
	currentIndex++;
	currentIndex = currentIndex & maxIndex;
}
float* DelayLine::getPrevious(unsigned int previousSampleIndex){
	int prevIndex = currentIndex - previousSampleIndex;

	if (prevIndex > 0){
		return &ringBuffer[prevIndex];
	}else{
		return &ringBuffer[maxIndex + prevIndex];
	}
}
float* DelayLine::getPreviousFract(float previousSampleIndex){
	static float ya_alt, output;
	unsigned int x1Index, x2Index;
	float frac, x1Val, x2Val;

	int prevIndex = currentIndex - (int)previousSampleIndex;
	x1Index = prevIndex;
	x2Index = prevIndex + 1;
	frac = (float)x2Index - previousSampleIndex;

	if (x1Index > 0){
		x1Val = ringBuffer[x1Index];
	}else{
		x1Val = ringBuffer[maxIndex + x1Index];
	}

	if (x2Index > 0){
		x2Val = ringBuffer[x2Index];
	}else{
		x2Val = ringBuffer[maxIndex + x2Index];
	}

	output = (x2Val+(1.0-frac)*x2Val - (1.0-frac)*ya_alt);
	return &output;
}

