/*
 * dummyController.hpp
 *
 *  Created on: 15 kwi 2018
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
