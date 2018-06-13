/*
 * triangleGen.hpp
 *
 *  Created on: 1 cze 2018
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

#ifndef TRIANGLEGEN_HPP_
#define TRIANGLEGEN_HPP_

#include "config.hpp"
#include "lfo.hpp"

class TriangleGen: public Lfo{
public:
	TriangleGen();
	void setToStart(float newFrequency, float newPhase);
	void changeFrequency(float newFrequency);
	float getSample();

	virtual ~TriangleGen();

private:
	float frequency;
	float phase;
	float diff;
	float output;
};

#endif /* TRIANGLEGEN_HPP_ */
