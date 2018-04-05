/*
 * playbackFx.hpp
 *
 *  Created on: 5 kwi 2018
 *      Author: SF
 */

#ifndef PLAYBACKFX_HPP_
#define PLAYBACKFX_HPP_

#include "effect.hpp"

class PlaybackFx: public IFX{
public:
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs);
	~PlaybackFx();

	virtual const std::string *getName();
	virtual void setSettings(int *settings);
	virtual int *getSettings();


private:
	 static const std::string nameFx;
};

#endif /* PLAYBACKFX_HPP_ */

