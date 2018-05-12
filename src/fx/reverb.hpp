/*
 * reverb.hpp
 *
 *  Created on: 11 maj 2018
 *      Author: SF
 */

#ifndef REVERB_HPP_
#define REVERB_HPP_

#include "effect.hpp"

//caps
#include "Reverb.h"

class Reverb: public IFX{
public:
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs);
	Reverb(IDetector *newUserInput);
	~Reverb();

	const std::string *getName();
	std::vector<Setting> *getSettings();

private:
	 static const std::string nameFx;

	 std::unique_ptr<JVRev> jvReverb;

};

#endif /* REVERB_HPP_ */
