/*
 * conifg.hpp
 *
 *  Created on: 23 mar 2018
 *      Author: SF
 */

#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <memory>
#include <thread>
#include <list>
#include <string>
#include <cmath>

//#define GTK_KEYBOARD_LOOP

const unsigned int DEFAULT_RESERVED_FX_LIST_SIZE = 8;

/*
 * color for fx list dialog
 */
namespace fxDialogListColor{
	const std::string selectedButtonCollor 		= "yellow";
	const std::string unselectedButtonCollor 	= "white";
}


enum ControllerInput{
	pot1,
	pot2,
	pot3,
	pot4,
	pot5,
	pot6,
	pot7,
	pot8,
	btn1,
	btn2,
	btn3,
	btn4,
	foot1,
	foot2,
	foot3
};

enum DialogWindowBtn{
	cancelBtn,
	addNextBtn,
	movelBtn,
	deletelBtn
};

#endif /* CONFIG_HPP_ */
