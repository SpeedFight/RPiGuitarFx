/*
 * keyboard.cpp
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

#include "keyboard.hpp"
#include <gdk/gdkkeysyms.h>


gboolean Keyboard::isQ, Keyboard::isA, Keyboard::isZ, Keyboard::isW, Keyboard::isS, Keyboard::isX, Keyboard::isE, Keyboard::isD, Keyboard::isC, Keyboard::isR, Keyboard::isF, Keyboard::isV, Keyboard::is1, Keyboard::is2, Keyboard::is3;

	Keyboard::Keyboard(int argc, char * argv[]){
		isQ= isA= isZ= isW= isS= isX= isE= isD= isC= isR= isF= isV= is1= is2= is3 = FALSE;

		controllerValues.fill(0);
		app = Gtk::Application::create(argc, argv, "RPiGFX.keyboard", Gio::APPLICATION_NON_UNIQUE);

		app->hold();
		window.reset(new Gtk::Window());
		window->set_title("keyboard input");
		window->set_default_size(250, 50);
		window->signal_key_press_event().connect(sigc::mem_fun(*this, &Keyboard::on_key_press));
		window->signal_key_release_event().connect(sigc::mem_fun(*this, &Keyboard::on_key_release));
		window->show();
	}

	bool Keyboard::on_key_press(GdkEventKey* event){
		switch (event->keyval) {
			case GDK_KEY_q: Keyboard::isQ = TRUE; break;
			case GDK_KEY_z: Keyboard::isZ = TRUE; break;

			case GDK_KEY_w: Keyboard::isW = TRUE; break;
			case GDK_KEY_x: Keyboard::isX = TRUE; break;

			case GDK_KEY_e: Keyboard::isE = TRUE; break;
			case GDK_KEY_c: Keyboard::isC = TRUE; break;

			case GDK_KEY_r: Keyboard::isR = TRUE; break;
			case GDK_KEY_v: Keyboard::isV = TRUE; break;

			case GDK_KEY_a:	Keyboard::isA = TRUE; controllerValues[ControllerInput::btn1] = 1; break;
			case GDK_KEY_s: Keyboard::isS = TRUE; controllerValues[ControllerInput::btn2] = 1; break;
			case GDK_KEY_d: Keyboard::isD = TRUE; controllerValues[ControllerInput::btn3] = 1; break;
			case GDK_KEY_f: Keyboard::isF = TRUE; controllerValues[ControllerInput::btn4] = 1; break;
			case GDK_KEY_1: Keyboard::is1 = TRUE; controllerValues[ControllerInput::foot1] = 1; break;
			case GDK_KEY_2: Keyboard::is2 = TRUE; controllerValues[ControllerInput::foot2] = 1; break;
			case GDK_KEY_3: Keyboard::is3 = TRUE; controllerValues[ControllerInput::foot3] = 1; break;
			default: break;
		}

		if(isA){
			if(isQ){
				++controllerValues[ControllerInput::pot5];
			}else if(isZ){
				--controllerValues[ControllerInput::pot5];
			}
		}else{
			if(isQ){
				++controllerValues[ControllerInput::pot1];
			}else if(isZ){
				--controllerValues[ControllerInput::pot1];
			}
		}

		if(isS){
			if(isW){
				++controllerValues[ControllerInput::pot6];
			}else if(isX){
				--controllerValues[ControllerInput::pot6];
			}
		}else{
			if(isW){
				++controllerValues[ControllerInput::pot2];
			}else if(isX){
				--controllerValues[ControllerInput::pot2];
			}
		}

		if(isD){
			if(isE){
				++controllerValues[ControllerInput::pot7];
			}else if(isC){
				--controllerValues[ControllerInput::pot7];
			}
		}else{
			if(isE){
				++controllerValues[ControllerInput::pot3];
			}else if(isC){
				--controllerValues[ControllerInput::pot3];
			}
		}

		if(isF){
			if(isR){
				++controllerValues[ControllerInput::pot8];
			}else if(isV){
				--controllerValues[ControllerInput::pot8];
			}
		}else{
			if(isR){
				++controllerValues[ControllerInput::pot4];
			}else if(isV){
				--controllerValues[ControllerInput::pot4];
			}
		}

//		std::cout<<"pot1val: "<<controllerValues[ControllerInput::pot1]<<std::endl;
//		std::cout<<"pot2val: "<<controllerValues[ControllerInput::pot2]<<std::endl;
//		std::cout<<"pot3val: "<<controllerValues[ControllerInput::pot3]<<std::endl;
//		std::cout<<"pot4val: "<<controllerValues[ControllerInput::pot4]<<std::endl;
//		std::cout<<"pot5val: "<<controllerValues[ControllerInput::pot5]<<std::endl;
//		std::cout<<"pot6val: "<<controllerValues[ControllerInput::pot6]<<std::endl;
//		std::cout<<"pot7val: "<<controllerValues[ControllerInput::pot7]<<std::endl;
//		std::cout<<"pot8val: "<<controllerValues[ControllerInput::pot8]<<std::endl;
//		std::cout<<"btn1val: "<<controllerValues[ControllerInput::btn1]<<std::endl;
//		std::cout<<"btn2val: "<<controllerValues[ControllerInput::btn2]<<std::endl;
//		std::cout<<"btn3val: "<<controllerValues[ControllerInput::btn3]<<std::endl;
//		std::cout<<"btn4val: "<<controllerValues[ControllerInput::btn4]<<std::endl;
//		std::cout<<"foot1val: "<<controllerValues[ControllerInput::foot1]<<std::endl;
//		std::cout<<"foot2val: "<<controllerValues[ControllerInput::foot2]<<std::endl;
//		std::cout<<"foot3val: "<<controllerValues[ControllerInput::foot3]<<std::endl;

		return GDK_EVENT_PROPAGATE;
	}

	bool Keyboard::on_key_release(GdkEventKey* event){
		switch (event->keyval) {
			case GDK_KEY_q: Keyboard::isQ = FALSE; break;
			case GDK_KEY_z: Keyboard::isZ = FALSE; break;

			case GDK_KEY_w: Keyboard::isW = FALSE; break;
			case GDK_KEY_x: Keyboard::isX = FALSE; break;

			case GDK_KEY_e: Keyboard::isE = FALSE; break;
			case GDK_KEY_c: Keyboard::isC = FALSE; break;

			case GDK_KEY_r: Keyboard::isR = FALSE; break;
			case GDK_KEY_v: Keyboard::isV = FALSE; break;

			case GDK_KEY_a:	Keyboard::isA = FALSE; controllerValues[ControllerInput::btn1] = 0; break;
			case GDK_KEY_s: Keyboard::isS = FALSE; controllerValues[ControllerInput::btn2] = 0; break;
			case GDK_KEY_d: Keyboard::isD = FALSE; controllerValues[ControllerInput::btn3] = 0; break;
			case GDK_KEY_f: Keyboard::isF = FALSE; controllerValues[ControllerInput::btn4] = 0; break;
			case GDK_KEY_1: Keyboard::is1 = FALSE; controllerValues[ControllerInput::foot1] = 0; break;
			case GDK_KEY_2: Keyboard::is2 = FALSE; controllerValues[ControllerInput::foot2] = 0; break;
			case GDK_KEY_3: Keyboard::is3 = FALSE; controllerValues[ControllerInput::foot3] = 0; break;
			default: break;
		}

//		std::cout<<"pot1val: "<<controllerValues[ControllerInput::pot1]<<std::endl;
//		std::cout<<"pot2val: "<<controllerValues[ControllerInput::pot2]<<std::endl;
//		std::cout<<"pot3val: "<<controllerValues[ControllerInput::pot3]<<std::endl;
//		std::cout<<"pot4val: "<<controllerValues[ControllerInput::pot4]<<std::endl;
//		std::cout<<"pot5val: "<<controllerValues[ControllerInput::pot5]<<std::endl;
//		std::cout<<"pot6val: "<<controllerValues[ControllerInput::pot6]<<std::endl;
//		std::cout<<"pot7val: "<<controllerValues[ControllerInput::pot7]<<std::endl;
//		std::cout<<"pot8val: "<<controllerValues[ControllerInput::pot8]<<std::endl;
//		std::cout<<"btn1val: "<<controllerValues[ControllerInput::btn1]<<std::endl;
//		std::cout<<"btn2val: "<<controllerValues[ControllerInput::btn2]<<std::endl;
//		std::cout<<"btn3val: "<<controllerValues[ControllerInput::btn3]<<std::endl;
//		std::cout<<"btn4val: "<<controllerValues[ControllerInput::btn4]<<std::endl;
//		std::cout<<"foot1val: "<<controllerValues[ControllerInput::foot1]<<std::endl;
//		std::cout<<"foot2val: "<<controllerValues[ControllerInput::foot2]<<std::endl;
//		std::cout<<"foot3val: "<<controllerValues[ControllerInput::foot3]<<std::endl;

		return GDK_EVENT_PROPAGATE;
	}

	void Keyboard::pollForEvents(){
#ifdef GTK_KEYBOARD_LOOP
		app->run();
#endif
	}

	int *Keyboard::getInputHandler(ControllerInput controllerInput){
		return &controllerValues[controllerInput];
	}
