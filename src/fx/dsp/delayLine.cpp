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
float* DelayLine::getPreviousFract(float previousSample){

}

