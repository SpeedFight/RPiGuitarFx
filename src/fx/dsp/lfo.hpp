/*
 * lfo.hpp
 *
 *  Created on: 1 cze 2018
 *      Author: konoha
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

#ifndef LFO_HPP_
#define LFO_HPP_

#include "config.hpp"


class Lfo{
public:
	Lfo(){};
	virtual void setToStart(float newFrequency, float newPhase) = 0;
	virtual void changeFrequency(float newFrequency) = 0;
	virtual float getSample() = 0;

	virtual ~Lfo() {};
};



#endif /* LFO_HPP_ */
