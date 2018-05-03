/*
 * toneStackEq.hpp
 *
 *  Created on: 2 maj 2018
 *      Author: SF
 */

#ifndef TONESTACKEQ_HPP_
#define TONESTACKEQ_HPP_

#include "effect.hpp"

class ToneStackEq: public IFX{
public:
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs);
	ToneStackEq(IDetector *newUserInput);
	~ToneStackEq();

	const std::string *getName();
	std::vector<Setting> *getSettings();

private:
	 static const std::string nameFx;
	 float C1, C2, C3, R1, R2, R3, R4;
	 float fs;
};



#endif /* TONESTACKEQ_HPP_ */
