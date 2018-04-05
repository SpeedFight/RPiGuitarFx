/*
 * playbackFx.cpp
 *
 *  Created on: 24 mar 2018
 *      Author: SF
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
PlaybackFx::~PlaybackFx() {};

const std::string *PlaybackFx::getName(){
	return &PlaybackFx::nameFx;
}

void PlaybackFx::setSettings(int *settings){
	//no settings in this FX
}

int *PlaybackFx::getSettings(){
	//no settings in this FX
}


