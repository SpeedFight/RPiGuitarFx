/*
 * dummyController.hpp
 *
 *  Created on: 15 kwi 2018
 *      Author: SF
 */

#ifndef DUMMYCONTROLLER_HPP_
#define DUMMYCONTROLLER_HPP_

#include "controller.hpp"
#include "config.hpp"

class DummyController: public IDetector{
public:
	DummyController(int argc, char * argv[]);
	void pollForEvents(void);
	int *getInputHandler(ControllerInput controllerInput);
	~DummyController() {};
private:
	std::array<int,15> controllerValues;
};

#endif /* DUMMYCONTROLLER_HPP_ */
