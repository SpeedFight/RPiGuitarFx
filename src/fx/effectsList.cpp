/*
 * effectsList.cpp
 *
 *  Created on: 26 kwi 2018
 *      Author: SF
 */

#include "effectsList.hpp"

AvaibleFxList::AvaibleFxList(IDetector *newUserInput){
	fxlist.push_back(std::unique_ptr<IFX>(new PlaybackFx(newUserInput)));
	fxlist.push_back(std::unique_ptr<IFX>(new SimpleOverdriveFx(newUserInput)));
	fxlist.push_back(std::unique_ptr<IFX>(new ToneStackEq(newUserInput)));
	fxlist.push_back(std::unique_ptr<IFX>(new Reverb(newUserInput)));
}


IFX *FxFactory::createFx(int fxNum, IDetector *newUserInput){
	std::cout<<"fxNum "<<fxNum<<std::endl;
	switch (fxNum) {
		case 0: return new PlaybackFx(newUserInput); break; //playback FX always first!
		case 1: return new SimpleOverdriveFx(newUserInput); break;
		case 2: return new ToneStackEq(newUserInput); break;
		case 3: return new Reverb(newUserInput); break;
		default: return nullptr; break;
	}
}
