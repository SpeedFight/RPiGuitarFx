/*
 * simpleOverdriveFX.hpp
 *
 *  Created on: 5 kwi 2018
 *      Author: konoha
 */

#ifndef SIMPLEOVERDRIVEFX_HPP_
#define SIMPLEOVERDRIVEFX_HPP_

#include "effect.hpp"

class SimpleOverdriveFx: public IFX{
public:

	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs);
	SimpleOverdriveFx(IDetector *newUserInput);
	~SimpleOverdriveFx();

	const std::string *getName();
	std::vector<Setting> *getSettings();


private:
	 static const std::string nameFx;
};




#endif /* SIMPLEOVERDRIVEFX_HPP_ */
