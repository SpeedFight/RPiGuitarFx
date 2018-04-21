/*
 * effectsList.hpp
 *
 *  Created on: 5 kwi 2018
 *      Author: konoha
 */

#ifndef EFFECTSLIST_HPP_
#define EFFECTSLIST_HPP_

#include "config.hpp"

#include "playbackFx.hpp"
#include "simpleOverdriveFX.hpp"

class AvaibleFxList{
public:
	AvaibleFxList(IDetector *newUserInput){
		fxlist.push_back(std::unique_ptr<IFX>(new PlaybackFx(newUserInput)));
		fxlist.push_back(std::unique_ptr<IFX>(new SimpleOverdriveFx(newUserInput)));
	}
	std::vector<std::unique_ptr<IFX>> fxlist;
};

#endif /* EFFECTSLIST_HPP_ */
