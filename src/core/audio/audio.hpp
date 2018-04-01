/*
 * audio.hpp
 *
 *  Created on: 23 mar 2018
 *      Author: SF
 */

#ifndef AUDIO_HPP_
#define AUDIO_HPP_

#include <jackaudioio.hpp>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "effect.hpp"

#define MIN(x,y) ((x) < (y) ? (x) : (y))

class Audio: public JackCpp::AudioIO {
	public:
		// Your audio callback. All audio processing goes in this function.
		virtual int audioCallback(jack_nframes_t nframes, audioBufVector inBufs, audioBufVector outBufs);

		Audio(FXList *fxList);

	private:
		FXList *fxList;
};


#endif /* AUDIO_HPP_ */
