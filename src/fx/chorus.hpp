/*
 * chorus.hpp
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

#ifndef CHORUS_HPP_
#define CHORUS_HPP_

#include "effect.hpp"
#include "config.hpp"

#include "dsp/delayLine.hpp"
#include "dsp/lfo.hpp"
#include "dsp/sinGen.hpp"
#include "dsp/triangleGen.hpp"


class Chorus: public IFX{
public:
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs);
	Chorus(IDetector *newUserInput);
	~Chorus();

	const std::string *getName();
	std::vector<Setting> *getSettings();

private:
	 static const std::string nameFx;

	 std::unique_ptr<DelayLine> delayLine;
	 std::unique_ptr<Lfo> gen1;
	 std::unique_ptr<Lfo> gen2;
	 std::unique_ptr<Lfo> gen3;

};



#endif /* CHORUS_HPP_ */
