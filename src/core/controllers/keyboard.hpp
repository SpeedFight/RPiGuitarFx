/*
 * keyboard.hpp
 *
 *  Created on: 2 kwi 2018
 *      Author: konoha
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

#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

#include "controller.hpp"
#include "config.hpp"

#include <gtkmm.h>

class Keyboard: public IDetector{
public:
	Keyboard(int argc, char * argv[]);
	void pollForEvents(void);
	int *getInputHandler(ControllerInput controllerInput);
	~Keyboard() {};

private:
	static gboolean isQ, isA, isZ, isW, isS, isX, isE, isD, isC, isR, isF, isV, is1, is2, is3;
	bool on_key_press(GdkEventKey* event);
	bool on_key_release(GdkEventKey* event);

	std::array<int,15> controllerValues;
	Glib::RefPtr<Gtk::Application> app;
	std::unique_ptr<Gtk::Window> window;

};




#endif /* KEYBOARD_HPP_ */
