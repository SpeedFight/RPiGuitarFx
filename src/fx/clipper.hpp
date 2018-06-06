/*
 * tube.hpp
 *
 *  Created on: 2 cze 2018
 *      Author: SF
 */

#ifndef CLIPPER_HPP_
#define CLIPPER_HPP_

#include "effect.hpp"
#include "config.hpp"

#include "dsp/upSample.hpp"


class Clipper: public IFX{
public:
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs);
	Clipper(IDetector *newUserInput);
	~Clipper();

	const std::string *getName();
	std::vector<Setting> *getSettings();

private:
	 static const std::string nameFx;

#ifndef __arm__
	 std::unique_ptr<UpDownSample> upSampler;
#endif
};


#endif /* CLIPPER_HPP_ */
