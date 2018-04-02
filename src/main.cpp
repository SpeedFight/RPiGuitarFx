/*
 * main.cpp
 *
 *  Created on: 23 mar 2018
 *      Author: SF
 */

#include "config.hpp"
#include "audio.hpp"
#include "effect.hpp"


using namespace std;

int main( int argc, char * argv[] )
{
	unique_ptr<FXList> fxList(new FXList());

	fxList->getFXList()->push_back(shared_ptr<IFX>(new PlaybackFx()));

	unique_ptr<Audio> input = unique_ptr<Audio>(new Audio(fxList.get()));

	sleep(5);		// sleep to allow the callback to run for 50 seconds.
	fxList.reset();
	input.reset();

    return 0;
}
