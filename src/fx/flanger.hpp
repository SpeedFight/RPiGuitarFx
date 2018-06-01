/*
 * flanger.hpp
 *
 *  Created on: 1 cze 2018
 *      Author: konoha
 */

#ifndef FLANGER_HPP_
#define FLANGER_HPP_

#include "effect.hpp"
#include "config.hpp"

#include "dsp/delayLine.hpp"
#include "dsp/sinGen.hpp"


class Flanger: public IFX{
public:
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs);
	Flanger(IDetector *newUserInput);
	~Flanger();

	const std::string *getName();
	std::vector<Setting> *getSettings();

private:
	 static const std::string nameFx;

	 std::unique_ptr<DelayLine> delayLine;
	 std::unique_ptr<SinGen> sinGen;

};

#endif /* FLANGER_HPP_ */
