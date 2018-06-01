/*
 * lfo.hpp
 *
 *  Created on: 1 cze 2018
 *      Author: konoha
 */

#ifndef LFO_HPP_
#define LFO_HPP_

#include "config.hpp"


class Lfo{
public:
	Lfo(){};
	virtual void setToStart(float newFrequency, float newPhase) = 0;
	virtual void changeFrequency(float newFrequency) = 0;
	virtual float getSample() = 0;

	virtual ~Lfo() {};
};



#endif /* LFO_HPP_ */
