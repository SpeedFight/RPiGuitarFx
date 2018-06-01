/*
 * oversample.hpp
 *
 *  Created on: 1 cze 2018
 *      Author: SF
 */

#ifndef UPSAMPLE_HPP_
#define UPSAMPLE_HPP_

#include "config.hpp"
#include <jackaudioio.hpp>

enum SamplingMultiplier{
		x2 = 2,
		x4 = 4,
		x8 = 8
};

class UpDownSample{
public:
	UpDownSample(SamplingMultiplier mult, unsigned int inputBufferSize);
	JackCpp::AudioIO::audioBufVector* up(JackCpp::AudioIO::audioBufVector inBufs);
	void down(JackCpp::AudioIO::audioBufVector inBufs);
private:
	SamplingMultiplier mult;
	unsigned int bufferSize;
	JackCpp::AudioIO::audioBufVector output;
};

#endif /* UPSAMPLE_HPP_ */
