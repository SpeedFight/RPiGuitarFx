/*
 * main.cpp
 *
 *  Created on: 23 mar 2018
 *      Author: SF
 */

#include "config.hpp"
#include "audio.hpp"
#include "effect.hpp"
#include "controller.hpp"
#include "keyboard.hpp"

#include "effectsList.hpp"

//#include <ncursesw/ncurses.h>

int main( int argc, char * argv[] )
{
	std::unique_ptr<Keyboard> keys(new Keyboard());
	//std::thread inputKeys(&Keyboard::pollForEvents, keys.get());


	std::unique_ptr<FXList> fxList(new FXList());
	fxList->getFXList()->push_back(std::shared_ptr<IFX>(new PlaybackFx()));
	std::unique_ptr<Audio> input = std::unique_ptr<Audio>(new Audio(fxList.get()));

	sleep(50);		// sleep to allow the callback to run for 50 seconds.
	fxList.reset();
	input.reset();
	keys.reset();
    return 0;
}
