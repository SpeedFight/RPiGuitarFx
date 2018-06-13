/*
 * nCoursesKey.hpp
 *
 *  Created on: 4 maj 2018
 *      Author: SF
 */

/*
RPiGuitarFx
Copyright (C) 2018  SpeedFight

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
