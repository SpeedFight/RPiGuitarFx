/*
 * delay.hpp
 *
 *  Created on: 31 maj 2018
 *      Author: SF
 */

#ifndef DELAY_HPP_
#define DELAY_HPP_

#include "effect.hpp"

class Delay: public IFX{
public:
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs);
	Delay(IDetector *newUserInput);
	~Delay();

	const std::string *getName();
	std::vector<Setting> *getSettings();

private:
	 static const std::string nameFx;
};


#endif /* DELAY_HPP_ */
