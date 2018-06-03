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

#include "dsp/IIR.hpp"

//enum SamplingMultiplier{
//		x2 = 2,
//		x4 = 4,
//		x8 = 8
//};

class UpDownSample{
public:
	UpDownSample(audioSettings::SamplingMultiplier mult, unsigned int inputBufferSize);
	std::array<float,1024>* up(JackCpp::AudioIO::audioBufVector inBufs);
	void down(JackCpp::AudioIO::audioBufVector outBufs);
private:
	audioSettings::SamplingMultiplier mult;
	unsigned int bufferSize;
	std::array<float,1024> output;


	std::unique_ptr<IIR> interpolationFilter;
	std::unique_ptr<IIR> antiAliasingFilter;
};

#endif /* UPSAMPLE_HPP_ */
