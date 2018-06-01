/*
 * exampleFx.hpp
 *
 *  Created on: 11 maj 2018
 *      Author: SF
 */

#ifndef EXAMPLEFX_HPP_
#define EXAMPLEFX_HPP_

#include "effect.hpp"
#include "config.hpp"

class ExampleFx: public IFX{
public:
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs);
	ExampleFx(IDetector *newUserInput);
	~ExampleFx();

	const std::string *getName();
	std::vector<Setting> *getSettings();

private:
	 static const std::string nameFx;

};

#endif /* EXAMPLEFX_HPP_ */
