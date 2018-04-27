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

#include "rotaryencoder.hpp"

class EncoderButton: public IButton{
public:
	EncoderButton();
	virtual int getValue(void);
	virtual ~EncoderButton(void);

protected:
	char character;
};

class EncoderPot: public EncoderButton{
public:
	EncoderPot();
	virtual int getValue(void);

protected:
	char character;
};

class Encoder: public IDetector{
public:
	Encoder(int argc, char * argv[]);
	void pollForEvents(void);
	int *getInputHandler(ControllerInput controllerInput);
	~Encoder() {};

private:
	std::array<int,15> controllerValues;

};


#endif
#endif /* ENCODER_HPP_ */
