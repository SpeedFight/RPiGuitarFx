/*
 * delayLine.hpp
 *
 *  Created on: 31 maj 2018
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

#ifndef DELAYLINE_HPP_
#define DELAYLINE_HPP_

#include "config.hpp"

/*
 * digital delay line
 *
 * toBuffer push to newest index and increment index
 * max previous sample is maxIndex late
 */
class DelayLine{
public:
	DelayLine(unsigned int powerOfTwoSize);
	void toBuffer(float newSample);
	float *getPrevious(unsigned int previousSampleIndex);
	float *getPreviousFract(float previousSampleIndex);

private:
	std::vector<float> ringBuffer;
	unsigned int currentIndex;
	const unsigned int maxIndex;
};



#endif /* DELAYLINE_HPP_ */
