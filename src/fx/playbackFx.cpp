/*
 * playbackFx.cpp
 *
 *  Created on: 24 mar 2018
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

#include "playbackFx.hpp"

#define MIN(x,y) ((x) < (y) ? (x) : (y))

const std::string PlaybackFx::nameFx("Playback");

/*
 * Just copy input to output;
 */
void PlaybackFx::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){

	for(unsigned int i = 0; i < MIN(inBufs.size(), outBufs.size()); i++){
		for(unsigned int j = 0; j < nframes; j++)
			outBufs[i][j] = inBufs[i][j];
	}
}
PlaybackFx::PlaybackFx(IDetector *newUserInput):
		IFX(newUserInput)
		{
	;
}


PlaybackFx::~PlaybackFx() {}

const std::string *PlaybackFx::getName(){
	return &PlaybackFx::nameFx;
}

std::vector<Setting> *PlaybackFx::getSettings(){

}


