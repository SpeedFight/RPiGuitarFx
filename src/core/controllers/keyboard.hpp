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
	std::array<int,12> controllerValues;
	const static char pot1up = 'q';
	const static char pot1btn = 'a';
	const static char pot1down = 'z';

	const static char pot2up = 'w';
	const static char pot2btn = 's';
	const static char pot2down = 'x';

	const static char pot3up = 'e';
	const static char pot3btn = 'd';
	const static char pot3down = 'c';

	const static char pot4up = 'r';
	const static char pot4btn = 'f';
	const static char pot4down = 'v';

	const static char foot1 = '1';
	const static char foot2 = '2';
};




#endif /* KEYBOARD_HPP_ */
