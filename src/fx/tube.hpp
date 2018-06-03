/*
 * tube.hpp
 *
 *  Created on: 2 cze 2018
 *      Author: SF
 */

#ifndef TUBE_HPP_
#define TUBE_HPP_

#include "effect.hpp"
#include "config.hpp"

#include "dsp/upSample.hpp"
#include "dsp/IIR.hpp"


class Tube: public IFX{
public:
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs);
	Tube(IDetector *newUserInput);
	~Tube();

	const std::string *getName();
	std::vector<Setting> *getSettings();

private:
	 static const std::string nameFx;

	 std::unique_ptr<UpDownSample> upSampler;
};


#endif /* TUBE_HPP_ */
