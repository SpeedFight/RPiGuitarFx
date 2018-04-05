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
	virtual int *getInputHandler(ControllerInput controllerInput);
	virtual ~Keyboard() {};
private:
	static gboolean isQ, isA, isZ, isW, isS, isX, isE, isD, isC, isR, isF, isV, is1, is2, is3;
	static gboolean on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer user_data);
	static gboolean on_key_release(GtkWidget *widget, GdkEventKey *event, gpointer user_data);

	std::array<int,13> controllerValues;


};




#endif /* KEYBOARD_HPP_ */
