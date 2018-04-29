/*
 * audio.hpp
 *
 *  Created on: 23 mar 2018
 *      Author: SF
 */

#ifndef AUDIO_HPP_
#define AUDIO_HPP_

#include "config.hpp"
#include "effect.hpp"
#include <jackaudioio.hpp>
#include <chrono>

#define MIN(x,y) ((x) < (y) ? (x) : (y))

class Audio: public JackCpp::AudioIO {
	public:
		// Your audio callback. All audio processing goes in this function.
		virtual int audioCallback(jack_nframes_t nframes, audioBufVector inBufs, audioBufVector outBufs);

		Audio(FXList *fxList);
		~Audio();

	private:
		FXList *fxList;
};


#endif /* AUDIO_HPP_ */
