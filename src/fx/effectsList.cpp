/*
 * effectsList.cpp
 *
 *  Created on: 26 kwi 2018
 *      Author: SF
 */

#include "effectsList.hpp"

AvaibleFxList::AvaibleFxList(IDetector *newUserInput){
	fxlist.push_back(std::unique_ptr<IFX>(new PlaybackFx(newUserInput)));
	fxlist.push_back(std::unique_ptr<IFX>(new Clipper(newUserInput)));
	fxlist.push_back(std::unique_ptr<IFX>(new Fuzz(newUserInput)));
	fxlist.push_back(std::unique_ptr<IFX>(new ToneStackEq(newUserInput)));
	fxlist.push_back(std::unique_ptr<IFX>(new Delay(newUserInput)));
	fxlist.push_back(std::unique_ptr<IFX>(new Flanger(newUserInput)));
	fxlist.push_back(std::unique_ptr<IFX>(new Chorus(newUserInput)));
	fxlist.push_back(std::unique_ptr<IFX>(new Vibrato(newUserInput)));


}


IFX *FxFactory::createFx(int fxNum, IDetector *newUserInput){
	std::cout<<"fxNum "<<fxNum<<std::endl;
	switch (fxNum) {
		case 0: return new PlaybackFx(newUserInput); break; //playback FX always first!
		case 1: return new Clipper(newUserInput); break;
		case 2: return new Fuzz(newUserInput); break;
		case 3: return new ToneStackEq(newUserInput); break;
		case 4: return new Delay(newUserInput); break;
		case 5: return new Flanger(newUserInput); break;
		case 6: return new Chorus(newUserInput); break;
		case 7: return new Vibrato(newUserInput); break;

		default: return nullptr; break;
	}
}
