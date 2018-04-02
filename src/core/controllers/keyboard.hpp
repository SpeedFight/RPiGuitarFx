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
	Keyboard();
	virtual void pollForEvents(void);
	virtual int getValue(ControllerInput controllerInput);
	virtual ~Keyboard() {};
private:
	static gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data);
	std::array<int,12> controllerValues;
};




#endif /* KEYBOARD_HPP_ */
