/*
 * oversample.cpp
 *
 *  Created on: 1 cze 2018
 *      Author: SF
 */

#include <dsp/upSample.hpp>


UpDownSample::UpDownSample(audioSettings::SamplingMultiplier mult, unsigned int inputBufferSize):
	mult(mult),
	bufferSize(mult * inputBufferSize)
{
		output.reserve(bufferSize);
}

std::vector<float> UpDownSample::up(JackCpp::AudioIO::audioBufVector inBufs){

	unsigned int k = 0;
	for (unsigned int i = 0; i < bufferSize;) {
		output[i++] = inBufs[0][k++];
		for (int j = 0; j < mult - 1; ++j) {
			output[i++] = 0.0;
		}
	}

	return output;
}

void UpDownSample::down(JackCpp::AudioIO::audioBufVector outBufs){

	unsigned int k = 0;
	for (int i = 0; i < bufferSize / mult ; i) {
		outBufs[0][i++] = output[k];
		k += mult ;
	}
}






