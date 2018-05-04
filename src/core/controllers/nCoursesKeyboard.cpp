/*
 * nCoursesKey.cpp
 *
 *  Created on: 4 maj 2018
 *      Author: SF
 */

#include <nCoursesKeyboard.hpp>

	const char NCourseKeyboard::pot1Up = 'q';
	const char NCourseKeyboard::pot1Down = 'z';

	const char NCourseKeyboard::pot2Up = 'w';
	const char NCourseKeyboard::pot2Down = 'x';

	const char NCourseKeyboard::pot3Up = 'e';
	const char NCourseKeyboard::pot3Down = 'c';

	const char NCourseKeyboard::pot4Up = 'r';
	const char NCourseKeyboard::pot4Down = 'v';

	const char NCourseKeyboard::btn1 = 'a';
	const char NCourseKeyboard::btn2 = 's';
	const char NCourseKeyboard::btn3 = 'd';
	const char NCourseKeyboard::btn4 = 'f';

	const char NCourseKeyboard::foot1 = '1';
	const char NCourseKeyboard::foot2 = '2';
	const char NCourseKeyboard::foot3 = '3';

NCourseKeyboard::NCourseKeyboard()
{
	controllerValues.fill(0);
	pressedKeys.reserve(16);
	isQ= isA= isZ= isW= isS= isX= isE= isD= isC= isR= isF= isV= is1= is2= is3 = false;


}

void NCourseKeyboard::on_key_release(){
	isQ= isA= isZ= isW= isS= isX= isE= isD= isC= isR= isF= isV= is1= is2= is3 = false;
}

void NCourseKeyboard::on_key_press(){
	for(auto pressedKey : pressedKeys){
		switch(pressedKey){
			case pot1Up: 	isQ = true; break;
			case btn1: 		isA = true; break;
			case pot1Down: 	isZ = true; break;

			case pot2Up: 	isW = true; break;
			case btn2: 		isS = true; break;
			case pot2Down: 	isX = true; break;

			case pot3Up: 	isE = true; break;
			case btn3: 		isD = true; break;
			case pot3Down: 	isC = true; break;

			case pot4Up: 	isR = true; break;
			case btn4: 		isF = true; break;
			case pot4Down: 	isV = true; break;

			case foot1: 	is1 = true; break;
			case foot2: 	is2 = true; break;
			case foot3: 	is3 = true; break;

			default: break;
		}
	}
}

void NCourseKeyboard::pollForEvents(){
	initscr();
	clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
	timeout(50);

	while(1){
		std::this_thread::sleep_for (std::chrono::milliseconds(50));

		char c;

		while ((c = getch()) != ERR){
			pressedKeys.push_back(c);
		}
		on_key_release();
		on_key_press();
		pressedKeys.clear();

		if(isA){
			controllerValues[ControllerInput::btn1] = true;
			if(isQ){
				++controllerValues[ControllerInput::pot5];
			}else if(isZ){
				--controllerValues[ControllerInput::pot5];
			}
		}else{
			controllerValues[ControllerInput::btn1] = false;
			if(isQ){
				++controllerValues[ControllerInput::pot1];
			}else if(isZ){
				--controllerValues[ControllerInput::pot1];
			}
		}

		if(isS){
			controllerValues[ControllerInput::btn2] = true;
			if(isW){
				++controllerValues[ControllerInput::pot6];
			}else if(isX){
				--controllerValues[ControllerInput::pot6];
			}
		}else{
			controllerValues[ControllerInput::btn2] = false;
			if(isW){
				++controllerValues[ControllerInput::pot2];
			}else if(isX){
				--controllerValues[ControllerInput::pot2];
			}
		}

		if(isD){
			controllerValues[ControllerInput::btn3] = true;
			if(isE){
				++controllerValues[ControllerInput::pot7];
			}else if(isC){
				--controllerValues[ControllerInput::pot7];
			}
		}else{
			controllerValues[ControllerInput::btn3] = false;
			if(isE){
				++controllerValues[ControllerInput::pot3];
			}else if(isC){
				--controllerValues[ControllerInput::pot3];
			}
		}

		if(isF){
			controllerValues[ControllerInput::btn4] = true;
			if(isR){
				++controllerValues[ControllerInput::pot8];
			}else if(isV){
				--controllerValues[ControllerInput::pot8];
			}
		}else{
			controllerValues[ControllerInput::btn4] = false;
			if(isR){
				++controllerValues[ControllerInput::pot4];
			}else if(isV){
				--controllerValues[ControllerInput::pot4];
			}
		}


		clear();
		mvprintw(0, 0, "pot1val: 	%d", controllerValues[ControllerInput::pot1]);
		mvprintw(1, 0, "pot2val: 	%d", controllerValues[ControllerInput::pot2]);
		mvprintw(2, 0, "pot3val:	%d", controllerValues[ControllerInput::pot3]);
		mvprintw(3, 0, "pot4val:	%d", controllerValues[ControllerInput::pot4]);
		mvprintw(4, 0, "pot5val: 	%d", controllerValues[ControllerInput::pot5]);
		mvprintw(5, 0, "pot6val: 	%d", controllerValues[ControllerInput::pot6]);
		mvprintw(6, 0, "pot7val: 	%d", controllerValues[ControllerInput::pot7]);
		mvprintw(7, 0, "pot8val: 	%d", controllerValues[ControllerInput::pot8]);
		mvprintw(8, 0, "btn1val: 	%d", controllerValues[ControllerInput::btn1]);
		mvprintw(9, 0, "btn2val: 	%d", controllerValues[ControllerInput::btn2]);
		mvprintw(10, 0,"btn3val: 	%d", controllerValues[ControllerInput::btn3]);
		mvprintw(11, 0,"btn4val: 	%d", controllerValues[ControllerInput::btn4]);

		mvprintw(12, 0, "foot1val: 	%d", controllerValues[ControllerInput::foot1]);
		mvprintw(13, 0, "foot2val: 	%d", controllerValues[ControllerInput::foot2]);
		mvprintw(14, 0, "foot3val: 	%d", controllerValues[ControllerInput::foot3]);


		refresh();

	}

	}

int *NCourseKeyboard::getInputHandler(ControllerInput controllerInput){
	return &controllerValues[controllerInput];
}
