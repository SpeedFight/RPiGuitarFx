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

void poolForInput(FXList *ptr){
	while(1){
	 ptr->getFXList()->front().get()->updateSettings();
	 std::this_thread::sleep_for (std::chrono::milliseconds(100));
	}
}

int main( int argc, char * argv[] )
{
	std::unique_ptr<Keyboard> keys(new Keyboard());
	std::thread guiThread(&Keyboard::pollForEvents, keys.get());


	std::unique_ptr<FXList> fxList(new FXList());
	//fxList->getFXList()->push_back(std::shared_ptr<IFX>(new PlaybackFx(keys.get())));
	fxList->getFXList()->push_back(std::shared_ptr<IFX>(new SimpleOverdriveFx(keys.get())));


	std::thread pollForInput(poolForInput, fxList.get());


	std::unique_ptr<Audio> input = std::unique_ptr<Audio>(new Audio(fxList.get()));

	std::this_thread::sleep_for (std::chrono::seconds(60*5));
	//sleep(60*5);
	fxList.reset();
	//input.reset();
	keys.reset();
    return 0;
}
