/*
 * playbackFx.cpp
 *
 *  Created on: 24 mar 2018
 *      Author: SF
 */

#include "effect.hpp"

#define MIN(x,y) ((x) < (y) ? (x) : (y))

void PlaybackFx::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){


	for(unsigned int i = 0; i < MIN(inBufs.size(), outBufs.size()); i++){
		std::cout<<i<<std::endl;
		for(unsigned int j = 0; j < nframes; j++)
			outBufs[i][j] = inBufs[i][j];	// A simple example: copy the input to the output.
	}
}
PlaybackFx::~PlaybackFx() {};


