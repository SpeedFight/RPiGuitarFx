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
inline float* DelayLine::getPrevious(unsigned int previousSampleIndex){
	int prevIndex = currentIndex - previousSampleIndex;

	if (prevIndex > 0){
		return &ringBuffer[prevIndex];
	}else{
		return &ringBuffer[maxIndex + prevIndex];
	}
}
float* DelayLine::getPreviousFract(float previousSampleIndex){
	static float ya_alt, output;
	int x1Index, x2Index;
	float frac, x1Val, x2Val;

	x1Index = previousSampleIndex;
	x2Index = x1Index + 1;

	frac = 0.5;

//	std::cout<<"x1Index "<<x1Index<<std::endl;
//	std::cout<<"x2Index "<<x2Index<<std::endl;
//	std::cout<<"frac "<<frac<<std::endl;
//	std::cout<<"previousSampleIndex "<<previousSampleIndex<<std::endl;

	x1Val = *getPrevious(x1Index);
	x2Val = *getPrevious(x2Index);

	output = (x1Val+frac*x2Val - frac*ya_alt);
//	output = x1Val*frac + x2Val*frac;
	ya_alt = output;
	return &output;
}

