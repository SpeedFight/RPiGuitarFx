/*
 * controller.hpp
 *
 *  Created on: 2 kwi 2018
 *      Author: konoha
 */

#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include "config.hpp"

/*
 * defined controllers
 * 4 potentiometers (encoder)
 * 4 buttons (each encoder is also button)
 * 2 buttons as footswitch
 */


class IController{
public:
	virtual int getValue(void) {return 0;};
	virtual ~IController(void) {};
};

class IDetector{
public:
	virtual void pollForEvents(void) {};
	virtual int *getInputHandler(ControllerInput controllerInput) = 0;
	virtual ~IDetector() {};
};

class IButton: public IController{
public:
	virtual int getValue(void) = 0;
	virtual ~IButton(void) {};
};

class IPotentiometer: public IController{
public:
	virtual int getValue(void) = 0;
	virtual ~IPotentiometer(void) {};
};


#endif /* CONTROLLER_HPP_ */
