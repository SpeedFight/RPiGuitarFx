/*
 * simpleOverdriveFX.hpp
 *
 *  Created on: 5 kwi 2018
 *      Author: SF
 */

#ifndef FUZZ_HPP_
#define FUZZ_HPP_

#include "effect.hpp"

#include "dsp/upSample.hpp"

class Fuzz: public IFX{
public:
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs);
	Fuzz(IDetector *newUserInput);
	~Fuzz();

	const std::string *getName();
	std::vector<Setting> *getSettings();

private:
	 static const std::string nameFx;

	 std::unique_ptr<UpDownSample> upSampler;
};




#endif /* FUZZ_HPP_ */
