/*
 * conifg.hpp
 *
 *  Created on: 23 mar 2018
 *      Author: konoha
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

const unsigned int DEFAULT_RESERVED_FX_LIST_SIZE = 8;


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


#endif /* CONFIG_HPP_ */
