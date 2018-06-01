/*
 * chorus.hpp
 *
 *  Created on: 1 cze 2018
 *      Author: SF
 */

#ifndef CHORUS_HPP_
#define CHORUS_HPP_

#include "effect.hpp"
#include "config.hpp"

#include "dsp/delayLine.hpp"
#include "dsp/sinGen.hpp"
#include "dsp/triangleGen.hpp"


class Chorus: public IFX{
public:
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs);
	Chorus(IDetector *newUserInput);
	~Chorus();

	const std::string *getName();
	std::vector<Setting> *getSettings();

private:
	 static const std::string nameFx;

	 std::unique_ptr<DelayLine> delayLine;
	 std::unique_ptr<Lfo> triangleGen1;
	 std::unique_ptr<Lfo> triangleGen2;
	 std::unique_ptr<Lfo> triangleGen3;

};



#endif /* CHORUS_HPP_ */
