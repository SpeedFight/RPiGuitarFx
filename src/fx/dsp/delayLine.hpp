/*
 * delayLine.hpp
 *
 *  Created on: 31 maj 2018
 *      Author: SF
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
