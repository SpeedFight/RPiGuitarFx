/*
 * toneStackEq.hpp
 *
 *  Created on: 2 maj 2018
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

#ifndef TONESTACKEQ_HPP_
#define TONESTACKEQ_HPP_

#include "effect.hpp"

class ToneStackEq: public IFX{
public:
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs);
	ToneStackEq(IDetector *newUserInput);
	~ToneStackEq();

	const std::string *getName();
	std::vector<Setting> *getSettings();

private:
	void calculateNewCoef(float b, float m, float t);

	 static const std::string nameFx;
	 float C1, C2, C3, R1, R2, R3, R4;


};



#endif /* TONESTACKEQ_HPP_ */
