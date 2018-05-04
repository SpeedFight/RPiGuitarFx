/*
 * keyboard.hpp
 *
 *  Created on: 2 kwi 2018
 *      Author: konoha
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
