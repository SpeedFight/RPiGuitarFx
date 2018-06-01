/*
 * vibrato.hpp
 *
 *  Created on: 1 cze 2018
 *      Author: SF
 */

#ifndef VIBRATO_HPP_
#define VIBRATO_HPP_

#include "effect.hpp"
#include "config.hpp"

#include "dsp/delayLine.hpp"
#include "dsp/sinGen.hpp"


class Vibrato: public IFX{
public:
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs);
	Vibrato(IDetector *newUserInput);
	~Vibrato();

	const std::string *getName();
	std::vector<Setting> *getSettings();

private:
	 static const std::string nameFx;

	 std::unique_ptr<DelayLine> delayLine;
	 std::unique_ptr<SinGen> sinGen;
};


#endif /* VIBRATO_HPP_ */
