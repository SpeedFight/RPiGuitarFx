/*
 * audio.hpp
 *
 *  Created on: 23 mar 2018
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

#ifndef AUDIO_HPP_
#define AUDIO_HPP_

#include "config.hpp"
#include "effect.hpp"
#include <jackaudioio.hpp>
#include <chrono>

#define MIN(x,y) ((x) < (y) ? (x) : (y))

/**
 * Connect to jack audio server and process audio effecs
 */
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
