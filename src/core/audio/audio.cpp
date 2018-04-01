/*
 * audio.cpp
 *
 *  Created on: 23 mar 2018
 *      Author: SF
 */

#include "audio.hpp"

Audio::Audio(FXList *newFxList) : JackCpp::AudioIO("RPiGuitarFX", 1,1), fxList(newFxList){
}

int Audio::audioCallback(jack_nframes_t nframes, audioBufVector inBufs, audioBufVector outBufs){

			for (auto& fxs : *fxList->getCurrentFXList()){
				fxs->process(nframes, inBufs, outBufs);
			}
			fxList->updateFX();
			return 0;
		}
