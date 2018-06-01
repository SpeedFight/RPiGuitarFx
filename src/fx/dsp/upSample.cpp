/*
 * oversample.cpp
 *
 *  Created on: 1 cze 2018
 *      Author: SF
 */

#include <dsp/upSample.hpp>


UpDownSample::UpDownSample(SamplingMultiplier mult, unsigned int inputBufferSize):
mult(mult),
bufferSize(mult * inputBufferSize)
{
		output.reserve(bufferSize);
}

JackCpp::AudioIO::audioBufVector* UpDownSample::up(JackCpp::AudioIO::audioBufVector inBufs){

	unsigned int k = 0;
	for (int i = 0; i < bufferSize ; i) {
		output[0][i++] = inBufs[0][k++];
		for (int j = 0; j < mult - 1; ++j) {
			output[0][i++] = 0.0;
		}
	}

	return &output;
}

void UpDownSample::down(JackCpp::AudioIO::audioBufVector outBufs){

	unsigned int k = 0;
	for (int i = 0; i < bufferSize / mult ; i) {
		outBufs[0][i++] = output[0][k];
		k += mult - 1;
	}
}






