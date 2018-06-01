/*
 * sinGen.hpp
 *
 *  Created on: 1 cze 2018
 *      Author: SF
 */

#ifndef SINGEN_HPP_
#define SINGEN_HPP_

#include "config.hpp"
#include "lfo.hpp"

class SinGen: public Lfo{
public:
	SinGen();
	void setToStart(float newFrequency, float newPhase);
	void changeFrequency(float newFrequency);
	float getSample();

	virtual ~SinGen();

private:
	float frequency;
	float phase;
	float phaseDiff;
	float output;

	float freqencyPeriod;
};



#endif /* SINGEN_HPP_ */
