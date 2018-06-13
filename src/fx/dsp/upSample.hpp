/*
 * oversample.hpp
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

#ifndef UPSAMPLE_HPP_
#define UPSAMPLE_HPP_

#include "config.hpp"
#include <jackaudioio.hpp>

#include "dsp/IIR.hpp"

//enum SamplingMultiplier{
//		x2 = 2,
//		x4 = 4,
//		x8 = 8
//};

class UpDownSample{
public:
	UpDownSample(audioSettings::SamplingMultiplier mult, unsigned int inputBufferSize);
	std::array<float,1024>* up(JackCpp::AudioIO::audioBufVector inBufs);
	void down(JackCpp::AudioIO::audioBufVector outBufs);
private:
	audioSettings::SamplingMultiplier mult;
	unsigned int bufferSize;
	std::array<float,1024> output;


	std::unique_ptr<IIR> interpolationFilter;
	std::unique_ptr<IIR> antiAliasingFilter;
};

#endif /* UPSAMPLE_HPP_ */
