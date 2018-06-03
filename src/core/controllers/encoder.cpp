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
			setupencoder ("ENC1", 23, 27,	YES,YES,YES,	-512,512,0,	200000,40000,25000,10000,5,10,20) ;
			setupencoder ("ENC2", 21, 22,	YES,YES,YES,	-512,512,0,	200000,40000,25000,10000,5,10,20) ;
			setupencoder ("ENC3", 4, 5,	YES,YES,YES,	-512,512,0,	200000,40000,25000,10000,5,10,20) ;
			setupencoder ("ENC4", 0, 2,	YES,YES,YES,		-512,512,0,	200000,40000,25000,10000,1,1,1) ;


	struct button *button =
		setupbutton("BTN1", 25, 1) ;
		setupbutton("BTN2", 26, 1) ;
		setupbutton("BTN3", 6, 1) ;
		setupbutton("BTN4", 3, 1) ;
}

int *Encoder::getInputHandler(ControllerInput controllerInput){
	return &controllerValues[controllerInput];
}


void Encoder::pollForEvents(){
	while(1){
		std::this_thread::sleep_for (std::chrono::milliseconds(10));
		unsigned char print = 0 ;
		int step;

		step = 8 ;
		struct button *button = buttons ;
		for (; button < buttons + numberofbuttons ; button++){
				print = 1 ;
				controllerValues[step] =  (1 && !button->value) ;
			++step ;
		}

		step = 0 ;
		struct encoder_type *encoder = encoders ;
		for (; encoder < encoders + numberofencoders ; encoder++){
			if (encoder->value != 0){
				print = 1 ;
				if(!controllerValues[step + 8]){
					controllerValues[step] += encoder->value ;
				} else {
					controllerValues[step + 4] += encoder->value ;
				}
				encoder->value = 0;
			}

			++step ;
			}

		// and if any value modified, then display the new value (and all others too)
		if (print){
//			std::cout<<"pot1val: "<<controllerValues[ControllerInput::pot1]<<std::endl;
//			std::cout<<"pot2val: "<<controllerValues[ControllerInput::pot2]<<std::endl;
//			std::cout<<"pot3val: "<<controllerValues[ControllerInput::pot3]<<std::endl;
//			std::cout<<"pot4val: "<<controllerValues[ControllerInput::pot4]<<std::endl;
//			std::cout<<"pot5val: "<<controllerValues[ControllerInput::pot5]<<std::endl;
//			std::cout<<"pot6val: "<<controllerValues[ControllerInput::pot6]<<std::endl;
//			std::cout<<"pot7val: "<<controllerValues[ControllerInput::pot7]<<std::endl;
//			std::cout<<"pot8val: "<<controllerValues[ControllerInput::pot8]<<std::endl;
//			std::cout<<"btn1val: "<<controllerValues[ControllerInput::btn1]<<std::endl;
//			std::cout<<"btn2val: "<<controllerValues[ControllerInput::btn2]<<std::endl;
//			std::cout<<"btn3val: "<<controllerValues[ControllerInput::btn3]<<std::endl;
//			std::cout<<"btn4val: "<<controllerValues[ControllerInput::btn4]<<std::endl;
//			std::cout<<"foot1val: "<<controllerValues[ControllerInput::foot1]<<std::endl;
//			std::cout<<"foot2val: "<<controllerValues[ControllerInput::foot2]<<std::endl;
//			std::cout<<"foot3val: "<<controllerValues[ControllerInput::foot3]<<std::endl;
		}
	}
}


#endif


