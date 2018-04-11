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

class KeyboardKey: public IButton{
public:
	KeyboardKey(char characterToDetect);
	virtual int getValue(void);
	virtual ~KeyboardKey(void);

protected:
	char character;
};

class KeyboardPot: public KeyboardKey{
public:
	KeyboardPot(char characterToDetect);
	virtual int getValue(void);

protected:
	char character;
};

class Keyboard: public IDetector{
public:
	Keyboard(int argc, char * argv[]);
	virtual void pollForEvents(void);
	virtual int *getInputHandler(ControllerInput controllerInput);
	virtual ~Keyboard() {};

private:
	static gboolean isQ, isA, isZ, isW, isS, isX, isE, isD, isC, isR, isF, isV, is1, is2, is3;
	bool on_key_press(GdkEventKey* event);
	bool on_key_release(GdkEventKey* event);

	std::array<int,15> controllerValues;
	Glib::RefPtr<Gtk::Application> app;
	std::unique_ptr<Gtk::Window> window;

};




#endif /* KEYBOARD_HPP_ */
