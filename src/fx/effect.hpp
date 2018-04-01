/*
 * effect.hpp
 *
 *  Created on: 23 mar 2018
 *      Author: SF
 */

#ifndef EFFECT_HPP_
#define EFFECT_HPP_

#include <jackaudioio.hpp>
#include <list>
#include <memory>
#include <iostream>

class IFX{
public:
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs) {};
	virtual ~IFX() {};
};

class FXList{

public:
	//FXList();
	const std::list<std::shared_ptr<IFX>>  *getCurrentFXList();
	std::list<std::shared_ptr<IFX>>  *getFXList();
	void updateFX();

private:
	std::list<std::shared_ptr<IFX>> futureFX;
	std::list<std::shared_ptr<IFX>> actualFX;
};

//effects lists

class PlaybackFx: public IFX{
public:
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs);
	~PlaybackFx();
};



#endif /* EFFECT_HPP_ */
