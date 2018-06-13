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

void ExampleFx::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){
	float set1 = settings.at(0).getValue();
	float set2 = settings.at(1).getValue();
	float set4 = settings.at(2).getValue();

	for(unsigned int i = 0; i <= nframes; ++i){
		outBufs[0][i] = inBufs[0][i];
	}

}

ExampleFx::ExampleFx(IDetector *newUserInput):
		IFX(newUserInput)
		{
	settings = std::vector<Setting>{
		Setting("setting 1", userInput->getInputHandler(ControllerInput::pot2), 50, 0, 100),
		Setting("setting 1", userInput->getInputHandler(ControllerInput::pot3), 50, 0, 100),
		Setting("setting 1", userInput->getInputHandler(ControllerInput::pot4), 50, 0, 100)};
}

ExampleFx::~ExampleFx(){
}

const std::string *ExampleFx::getName(){
	return &ExampleFx::nameFx;
}

std::vector<Setting> *ExampleFx::getSettings(){

}
