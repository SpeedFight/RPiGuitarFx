/*
 * nCoursesKey.hpp
 *
 *  Created on: 4 maj 2018
 *      Author: SF
 */

#ifndef NCOURSESKEYBOARD_HPP_
#define NCOURSESKEYBOARD_HPP_

#include "config.hpp"
#include "controller.hpp"

#include <ncurses.h>

class NCourseKeyboard: public IDetector{
public:
	NCourseKeyboard();
	void pollForEvents();
	int *getInputHandler(ControllerInput controllerInput);
	~NCourseKeyboard() {};

private:
	void on_key_press();
	void on_key_release();

	std::array<int,15> controllerValues;
	std::vector<char> pressedKeys;

	bool isQ, isA, isZ, isW, isS, isX, isE, isD, isC, isR, isF, isV, is1, is2, is3;

	static const char pot1Up;
	static const char pot1Down;

	static const char pot2Up;
	static const char pot2Down;

	static const char pot3Up;
	static const char pot3Down;

	static const char pot4Up;
	static const char pot4Down;

	static const char btn1;
	static const char btn2;
	static const char btn3;
	static const char btn4;

	static const char foot1;
	static const char foot2;
	static const char foot3;
};


#endif /* NCOURSESKEYBOARD_HPP_ */
