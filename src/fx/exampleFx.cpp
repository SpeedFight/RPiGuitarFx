/*
 * exampleFx.cpp
 *
 *  Created on: 11 maj 2018
 *      Author: SF
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

#include "exampleFx.hpp"

const std::string ExampleFx::nameFx("Example");

/**
 * @brief main function in effect
 * @param nframes amount of audio samples
 * @param inBufs to get data from
 * @param outBufs to put output data
 */
void ExampleFx::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){

	/**
	 * get user input
	 *
	 */
	float set1 = settings.at(0).getValue();
	float set2 = settings.at(1).getValue();
	float set3 = settings.at(2).getValue();
	float set4 = settings.at(2).getValue();

	for(unsigned int i = 0; i <= nframes; ++i){
		outBufs[0][i] = inBufs[0][i];
	}

}

ExampleFx::ExampleFx(IDetector *newUserInput):
		IFX(newUserInput)
		{
	settings = std::vector<Setting>{
		/**
		 * connect user input with effect settings
		 * Available encoders 2-4 then 6-8 (1 and 5 is encoder 1, normal and push-mode)
		 * To get all pot value check config.hpp ControllerInput enum
		 * Setting("visible name", userInput->getInputHandler(ControllerInput::pot_number), init_value, min_value, max_value),
		 */
		Setting("setting 1", userInput->getInputHandler(ControllerInput::pot2), 50, 0, 100),
		Setting("setting 2", userInput->getInputHandler(ControllerInput::pot3), 50, 0, 100),
		Setting("setting 3", userInput->getInputHandler(ControllerInput::pot4), 50, 0, 100),
		Setting("setting 4", userInput->getInputHandler(ControllerInput::pot6), 50, 0, 100),
	};
}

ExampleFx::~ExampleFx(){
}

const std::string *ExampleFx::getName(){
	return &ExampleFx::nameFx;
}

std::vector<Setting> *ExampleFx::getSettings(){

}
