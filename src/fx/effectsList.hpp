/*
 * effectsList.hpp
 *
 *  Created on: 5 kwi 2018
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

#ifndef EFFECTSLIST_HPP_
#define EFFECTSLIST_HPP_


#include "config.hpp"

#include "playbackFx.hpp"
#include <clipper.hpp>
#include <fuzz.hpp>
#include "toneStackEq.hpp"
#include "delay.hpp"
#include "flanger.hpp"
#include "chorus.hpp"
#include "vibrato.hpp"

/**
 * Contain all available effects in project.
 * If you add new FX, check .cpp file to append list of all effects
 */
class AvaibleFxList{
public:
	AvaibleFxList(IDetector *newUserInput);

	std::vector<std::unique_ptr<IFX>> fxlist;
};

/**
 * Return selected fx
 */
class FxFactory{
public:
	static IFX *createFx(int fxNum, IDetector *newUserInput);
};

#endif /* EFFECTSLIST_HPP_ */
