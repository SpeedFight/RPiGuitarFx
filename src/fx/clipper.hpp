/*
 * tube.hpp
 *
 *  Created on: 2 cze 2018
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

#ifndef CLIPPER_HPP_
#define CLIPPER_HPP_

#include "effect.hpp"
#include "config.hpp"

#include "dsp/upSample.hpp"


class Clipper: public IFX{
public:
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs);
	Clipper(IDetector *newUserInput);
	~Clipper();

	const std::string *getName();
	std::vector<Setting> *getSettings();

private:
	 static const std::string nameFx;

#ifndef __arm__
	 std::unique_ptr<UpDownSample> upSampler;
#endif
};


#endif /* CLIPPER_HPP_ */
