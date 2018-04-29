/*
 * encoder.cpp
 *
 *  Created on: 27 kwi 2018
 *      Author: SF
 */

#include "encoder.hpp"

#ifdef ROTARY_ENCODER

extern int numberofencoders ;
extern int numberofbuttons ;


Encoder::Encoder(){
	controllerValues.fill(0);
    wiringPiSetup () ;

	struct encoder_type *encoder =
	setupencoder ("ENC1",0,2,YES,YES,YES,-128,128,0,500000,40000,25000,10000,10,20,30) ;
	setupencoder ("ENC2",3,4,YES,YES,YES,-128,128,0,500000,40000,25000,10000,10,20,30) ;
	setupencoder ("ENC3",27,26,YES,YES,YES,-128,128,0,500000,40000,25000,10000,10,20,30) ;
	setupencoder ("ENC4",5,23,YES,YES,YES,-128,128,0,500000,40000,25000,10000,10,20,30) ;

	struct button *button =
	setupbutton("BTN1",7,1) ;
	setupbutton("BTN2",10,1) ;//10
	setupbutton("BTN3",6,1) ;
	setupbutton("BTN4",22,1) ; //22
}

int *Encoder::getInputHandler(ControllerInput controllerInput){
	return &controllerValues[controllerInput];
}


void Encoder::pollForEvents(){
	while(1){
		std::this_thread::sleep_for (std::chrono::milliseconds(50));

		int step = 0 ;
		unsigned char print = 0 ;

		// check if any rotary encoder modified value
		struct encoder_type *encoder = encoders ;
		for (; encoder < encoders + numberofencoders ; encoder++)
		{
			if (encoder->value != controllerValues[step])
			{
				print = 1 ;
				controllerValues[step] = encoder->value ;
			}
			++step ;
		}

//		step = 0 ;

		// check if any button modified value
		struct button *button = buttons ;
		for (; button < buttons + numberofbuttons ; button++)
		{
			if (button->value != controllerValues[step])
			{
				print = 1 ;
				controllerValues[step] = button->value ;


			}
			++step ;
		}

		// and if any value modified, then display the new value (and all others too)
		if (print)
		{
			std::cout<<"pot1val: "<<controllerValues[ControllerInput::pot1]<<std::endl;
			std::cout<<"pot2val: "<<controllerValues[ControllerInput::pot2]<<std::endl;
			std::cout<<"pot3val: "<<controllerValues[ControllerInput::pot3]<<std::endl;
			std::cout<<"pot4val: "<<controllerValues[ControllerInput::pot4]<<std::endl;
			std::cout<<"pot5val: "<<controllerValues[ControllerInput::pot5]<<std::endl;
			std::cout<<"pot6val: "<<controllerValues[ControllerInput::pot6]<<std::endl;
			std::cout<<"pot7val: "<<controllerValues[ControllerInput::pot7]<<std::endl;
			std::cout<<"pot8val: "<<controllerValues[ControllerInput::pot8]<<std::endl;
			std::cout<<"btn1val: "<<controllerValues[ControllerInput::btn1]<<std::endl;
			std::cout<<"btn2val: "<<controllerValues[ControllerInput::btn2]<<std::endl;
			std::cout<<"btn3val: "<<controllerValues[ControllerInput::btn3]<<std::endl;
			std::cout<<"btn4val: "<<controllerValues[ControllerInput::btn4]<<std::endl;
			std::cout<<"foot1val: "<<controllerValues[ControllerInput::foot1]<<std::endl;
			std::cout<<"foot2val: "<<controllerValues[ControllerInput::foot2]<<std::endl;
			std::cout<<"foot3val: "<<controllerValues[ControllerInput::foot3]<<std::endl;
			print = 0 ;
		}
	}
}

#endif


