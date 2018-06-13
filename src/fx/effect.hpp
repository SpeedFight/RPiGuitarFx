/*
 * effect.hpp
 *
 *  Created on: 23 mar 2018
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

#ifndef EFFECT_HPP_
#define EFFECT_HPP_

#include "config.hpp"
#include "controller.hpp"
#include <jackaudioio.hpp>

class Setting{
public:
	Setting(std::string newName, int *controllerValue, int initValue, int newMinValue, int newMaxValue);
	std::string *getName();
	void updatePotentiometers();
	int getValue();
	int getMaxValue();
	int getMinValue();

private:
	std::string name;
	int *valueFromController;
	int actualValue;
	const int maxValue;
	const int minValue;

};

class IFX{
public:
	IFX(IDetector *newUserInput);
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs) {};
	virtual ~IFX() {};

	virtual const std::string *getName() = 0;
	void updateSettings();
	std::vector<Setting> *getSettings();

protected:
	IDetector *userInput;
	std::vector<Setting> settings;

};


/**
 * @description List for actual effect list in audio loop with add/move/delete mechanism. This is basically core of guitar multieffect.
 * Contain 2 fx list (for non blocking edit, but this mechanism currently don't work)
 */
class FXList{
public:
	FXList();
	const std::vector<std::shared_ptr<IFX>>  *getCurrentFXList();
	std::vector<std::shared_ptr<IFX>>  *getFXList();
	void updateFXList();
	void updateFXParameters(int indxOfFxToUpdate);
	void addFX(IFX *newFx);
	void addFX(IFX *newFx, int newFxIndex);
	void moveFX(int fxToMoveIndex, int destinationIndex);
	void removeFX(unsigned int fxToRemoveIndex);


private:
	std::vector<std::shared_ptr<IFX>> futureFX;
	std::vector<std::shared_ptr<IFX>> actualFX;
};


#endif /* EFFECT_HPP_ */
