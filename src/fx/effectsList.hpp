/*
 * effectsList.hpp
 *
 *  Created on: 5 kwi 2018
 *      Author: SF
 */

#ifndef EFFECTSLIST_HPP_
#define EFFECTSLIST_HPP_

#include "config.hpp"

#include "playbackFx.hpp"
#include "simpleOverdriveFX.hpp"
#include "toneStackEq.hpp"
#include "reverb.hpp"
#include "delay.hpp"
#include "flanger.hpp"
#include "chorus.hpp"
#include "vibrato.hpp"
#include "tube.hpp"

class AvaibleFxList{
public:
	AvaibleFxList(IDetector *newUserInput);

	std::vector<std::unique_ptr<IFX>> fxlist;
};

class FxFactory{
public:
	static IFX *createFx(int fxNum, IDetector *newUserInput);
};

#endif /* EFFECTSLIST_HPP_ */
