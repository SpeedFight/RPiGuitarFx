/*
 * keyboard.cpp
 *
 *  Created on: 2 kwi 2018
 *      Author: konoha
 */

#include "keyboard.hpp"
#include <gdk/gdkkeysyms.h>



	Keyboard::Keyboard(){

		controllerValues.fill(0);
		GtkWidget *window;

		gtk_init(0,0);

		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK (gtk_main_quit), NULL);
		g_signal_connect (G_OBJECT (window), "key_press_event", G_CALLBACK (on_key_press), this);
		gtk_widget_show(window);

		gtk_main ();


	}

	gboolean Keyboard::on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data){
		int *values = reinterpret_cast<Keyboard*>(user_data)->controllerValues.data();
		switch (event->keyval) {
			case GDK_KEY_q: ++values[ControllerInput::pot1]; break;
			case GDK_KEY_z: --values[ControllerInput::pot1]; break;

			case GDK_KEY_w: ++values[ControllerInput::pot2]; break;
			case GDK_KEY_x: --values[ControllerInput::pot2]; break;

			case GDK_KEY_e: ++values[ControllerInput::pot3]; break;
			case GDK_KEY_c: --values[ControllerInput::pot3]; break;

			case GDK_KEY_r: ++values[ControllerInput::pot4]; break;
			case GDK_KEY_v: --values[ControllerInput::pot4]; break;

			case GDK_KEY_a: ++values[ControllerInput::btn1]; break;
			case GDK_KEY_s: ++values[ControllerInput::btn2]; break;
			case GDK_KEY_d: ++values[ControllerInput::btn3]; break;
			case GDK_KEY_f: ++values[ControllerInput::btn4]; break;
			case GDK_KEY_1: ++values[ControllerInput::foot1]; break;
			case GDK_KEY_2: ++values[ControllerInput::foot2]; break;
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
		}

	void Keyboard::pollForEvents(){

	}

	int Keyboard::getValue(ControllerInput controllerInput){

		return controllerValues[controllerInput];
	}
