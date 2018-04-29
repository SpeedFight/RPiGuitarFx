/*
 * encoder.hpp
 *
 *  Created on: 27 kwi 2018
 *      Author: SF
 */

#ifndef ENCODER_HPP_
#define ENCODER_HPP_

#include "config.hpp"
#include "controller.hpp"

#ifdef ROTARY_ENCODER

extern "C" {
#include <rotaryencoder.h>
}

class Encoder: public IDetector{
public:
	Encoder();
	void pollForEvents(void);
	int *getInputHandler(ControllerInput controllerInput);
	~Encoder() {};

private:
	std::array<int,15> controllerValues;
};


#endif
#endif /* ENCODER_HPP_ */
