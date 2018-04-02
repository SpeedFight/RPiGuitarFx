/*
 * keyboard.cpp
 *
 *  Created on: 2 kwi 2018
 *      Author: konoha
 */

#include "keyboard.hpp"

#include <ncursesw/ncurses.h>

	Keyboard::Keyboard(){

		controllerValues.fill(0);
	}

	void Keyboard::pollForEvents(){

		char input = ' ';
		while(1){


			std::this_thread::sleep_for(std::chrono::milliseconds(25));

			//while(!(input = getchar()))
			std::cout<<"input: ";
				input = getchar();
				std::cout<<input;
			switch (input) {
				case pot1up: controllerValues[ControllerInput::pot1]+=1; break;
				case pot1down: --controllerValues[ControllerInput::pot1]; break;

				case pot2up: ++controllerValues[ControllerInput::pot2]; break;
				case pot2down: --controllerValues[ControllerInput::pot2]; break;

				case pot3up: ++controllerValues[ControllerInput::pot3]; break;
				case pot3down: --controllerValues[ControllerInput::pot3]; break;

				case pot4up: ++controllerValues[ControllerInput::pot4]; break;
				case pot4down: --controllerValues[ControllerInput::pot4]; break;

				case pot1btn: ++controllerValues[ControllerInput::btn1]; break;
				case pot2btn: ++controllerValues[ControllerInput::btn2]; break;
				case pot3btn: ++controllerValues[ControllerInput::btn3]; break;
				case pot4btn: ++controllerValues[ControllerInput::btn4]; break;
				case foot1: ++controllerValues[ControllerInput::foot1]; break;
				case foot2: ++controllerValues[ControllerInput::foot2]; break;
				default: break;
			}
			std::cout<<controllerValues[0]<<std::endl;
		}
		return;
	}

	int Keyboard::getValue(ControllerInput controllerInput){

		return controllerValues[controllerInput];
	}
