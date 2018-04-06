/*
 * keyboard.cpp
 *
 *  Created on: 2 kwi 2018
 *      Author: konoha
 */

#include "keyboard.hpp"
#include <gdk/gdkkeysyms.h>

gboolean Keyboard::isQ, Keyboard::isA, Keyboard::isZ, Keyboard::isW, Keyboard::isS, Keyboard::isX, Keyboard::isE, Keyboard::isD, Keyboard::isC, Keyboard::isR, Keyboard::isF, Keyboard::isV, Keyboard::is1, Keyboard::is2, Keyboard::is3;

	Keyboard::Keyboard(){
		isQ= isA= isZ= isW= isS= isX= isE= isD= isC= isR= isF= isV= is1= is2= is3 = FALSE;

		controllerValues.fill(0);
		GtkWidget *window;

		gtk_init(0,0);
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK (gtk_main_quit), NULL);
		g_signal_connect (G_OBJECT (window), "key-press-event", G_CALLBACK (on_key_press), this);
		g_signal_connect (G_OBJECT (window), "key-release-event", G_CALLBACK (on_key_release), this);
		gtk_widget_show(window);
	}

	gboolean Keyboard::on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer user_data){
		int *values = reinterpret_cast<Keyboard*>(user_data)->controllerValues.data();
		switch (event->keyval) {
			case GDK_KEY_q: Keyboard::isQ = TRUE; break;
			case GDK_KEY_z: Keyboard::isZ = TRUE; break;

			case GDK_KEY_w: Keyboard::isW = TRUE; break;
			case GDK_KEY_x: Keyboard::isX = TRUE; break;

			case GDK_KEY_e: Keyboard::isE = TRUE; break;
			case GDK_KEY_c: Keyboard::isC = TRUE; break;

			case GDK_KEY_r: Keyboard::isR = TRUE; break;
			case GDK_KEY_v: Keyboard::isV = TRUE; break;

			case GDK_KEY_a:	Keyboard::isA = TRUE; values[ControllerInput::btn1] = 1; break;
			case GDK_KEY_s: Keyboard::isS = TRUE; values[ControllerInput::btn2] = 1; break;
			case GDK_KEY_d: Keyboard::isD = TRUE; values[ControllerInput::btn3] = 1; break;
			case GDK_KEY_f: Keyboard::isF = TRUE; values[ControllerInput::btn4] = 1; break;
			case GDK_KEY_1: Keyboard::is1 = TRUE; values[ControllerInput::foot1] = 1; break;
			case GDK_KEY_2: Keyboard::is2 = TRUE; values[ControllerInput::foot2] = 1; break;
			case GDK_KEY_3: Keyboard::is3 = TRUE; values[ControllerInput::foot3] = 1; break;
			default: break;
		}

		if(isA){
			if(isQ){
				++values[ControllerInput::pot5];
			}else if(isZ){
				--values[ControllerInput::pot5];
			}
		}else{
			if(isQ){
				++values[ControllerInput::pot1];
			}else if(isZ){
				--values[ControllerInput::pot1];
			}
		}

		if(isS){
			if(isW){
				++values[ControllerInput::pot6];
			}else if(isX){
				--values[ControllerInput::pot6];
			}
		}else{
			if(isW){
				++values[ControllerInput::pot2];
			}else if(isX){
				--values[ControllerInput::pot2];
			}
		}

		if(isD){
			if(isE){
				++values[ControllerInput::pot7];
			}else if(isC){
				--values[ControllerInput::pot7];
			}
		}else{
			if(isE){
				++values[ControllerInput::pot3];
			}else if(isC){
				--values[ControllerInput::pot3];
			}
		}

		if(isF){
			if(isR){
				++values[ControllerInput::pot8];
			}else if(isV){
				--values[ControllerInput::pot8];
			}
		}else{
			if(isR){
				++values[ControllerInput::pot4];
			}else if(isV){
				--values[ControllerInput::pot4];
			}
		}

		std::cout<<"pot1val: "<<values[ControllerInput::pot1]<<std::endl;
		std::cout<<"pot2val: "<<values[ControllerInput::pot2]<<std::endl;
		std::cout<<"pot3val: "<<values[ControllerInput::pot3]<<std::endl;
		std::cout<<"pot4val: "<<values[ControllerInput::pot4]<<std::endl;
		std::cout<<"pot5val: "<<values[ControllerInput::pot5]<<std::endl;
		std::cout<<"pot6val: "<<values[ControllerInput::pot6]<<std::endl;
		std::cout<<"pot7val: "<<values[ControllerInput::pot7]<<std::endl;
		std::cout<<"pot8val: "<<values[ControllerInput::pot8]<<std::endl;
		std::cout<<"btn1val: "<<values[ControllerInput::btn1]<<std::endl;
		std::cout<<"btn2val: "<<values[ControllerInput::btn2]<<std::endl;
		std::cout<<"btn3val: "<<values[ControllerInput::btn3]<<std::endl;
		std::cout<<"btn4val: "<<values[ControllerInput::btn4]<<std::endl;
		std::cout<<"foot1val: "<<values[ControllerInput::foot1]<<std::endl;
		std::cout<<"foot2val: "<<values[ControllerInput::foot2]<<std::endl;
		std::cout<<"foot3val: "<<values[ControllerInput::foot3]<<std::endl;

		return GDK_EVENT_PROPAGATE;
	}

	gboolean Keyboard::on_key_release(GtkWidget *widget, GdkEventKey *event, gpointer user_data){
		int *values = reinterpret_cast<Keyboard*>(user_data)->controllerValues.data();
		switch (event->keyval) {
			case GDK_KEY_q: Keyboard::isQ = FALSE; break;
			case GDK_KEY_z: Keyboard::isZ = FALSE; break;

			case GDK_KEY_w: Keyboard::isW = FALSE; break;
			case GDK_KEY_x: Keyboard::isX = FALSE; break;

			case GDK_KEY_e: Keyboard::isE = FALSE; break;
			case GDK_KEY_c: Keyboard::isC = FALSE; break;

			case GDK_KEY_r: Keyboard::isR = FALSE; break;
			case GDK_KEY_v: Keyboard::isV = FALSE; break;

			case GDK_KEY_a:	Keyboard::isA = FALSE; values[ControllerInput::btn1] = 0; break;
			case GDK_KEY_s: Keyboard::isS = FALSE; values[ControllerInput::btn2] = 0; break;
			case GDK_KEY_d: Keyboard::isD = FALSE; values[ControllerInput::btn3] = 0; break;
			case GDK_KEY_f: Keyboard::isF = FALSE; values[ControllerInput::btn4] = 0; break;
			case GDK_KEY_1: Keyboard::is1 = FALSE; values[ControllerInput::foot1] = 0; break;
			case GDK_KEY_2: Keyboard::is2 = FALSE; values[ControllerInput::foot2] = 0; break;
			case GDK_KEY_3: Keyboard::is3 = FALSE; values[ControllerInput::foot3] = 0; break;
			default: break;
		}

		std::cout<<"pot1val: "<<values[ControllerInput::pot1]<<std::endl;
		std::cout<<"pot2val: "<<values[ControllerInput::pot2]<<std::endl;
		std::cout<<"pot3val: "<<values[ControllerInput::pot3]<<std::endl;
		std::cout<<"pot4val: "<<values[ControllerInput::pot4]<<std::endl;
		std::cout<<"pot5val: "<<values[ControllerInput::pot5]<<std::endl;
		std::cout<<"pot6val: "<<values[ControllerInput::pot6]<<std::endl;
		std::cout<<"pot7val: "<<values[ControllerInput::pot7]<<std::endl;
		std::cout<<"pot8val: "<<values[ControllerInput::pot8]<<std::endl;
		std::cout<<"btn1val: "<<values[ControllerInput::btn1]<<std::endl;
		std::cout<<"btn2val: "<<values[ControllerInput::btn2]<<std::endl;
		std::cout<<"btn3val: "<<values[ControllerInput::btn3]<<std::endl;
		std::cout<<"btn4val: "<<values[ControllerInput::btn4]<<std::endl;
		std::cout<<"foot1val: "<<values[ControllerInput::foot1]<<std::endl;
		std::cout<<"foot2val: "<<values[ControllerInput::foot2]<<std::endl;
		std::cout<<"foot3val: "<<values[ControllerInput::foot3]<<std::endl;

		return GDK_EVENT_PROPAGATE;
	}

	void Keyboard::pollForEvents(){
		gtk_main ();
	}

	int *Keyboard::getInputHandler(ControllerInput controllerInput){
		return &controllerValues[controllerInput];
	}
