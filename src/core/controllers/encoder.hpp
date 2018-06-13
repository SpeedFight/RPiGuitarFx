/*
 * encoder.hpp
 *
 *  Created on: 27 kwi 2018
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

#ifndef ENCODER_HPP_
#define ENCODER_HPP_

#include "config.hpp"
#include "controller.hpp"

#ifdef ROTARY_ENCODER

#include <rotaryencoder.h>

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
