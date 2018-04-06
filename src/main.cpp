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
	 //ptr->getFXList()->front().get()->updateSettings();
//	 (ptr->getFXList())[0][0].get()->updateSettings();
//	 (ptr->getFXList())[0][0].get()->updateSettings();
	 ptr->getFXList()->begin()[0]->updateSettings();
	 std::this_thread::sleep_for (std::chrono::milliseconds(100));
	}
}
/*	TODO
 * 1) DONE zamienic liste na vector
 * 2) dodać klase do zarzadzania vectorem z efektami
 * 3) dodać mechanizm który wybiera efekt przyjmujący dane z potencjometrow
 * 4) testowy interfejs w konsoli
 * 4) gui -> gtk3
 */

int main( int argc, char * argv[] )
{
	std::unique_ptr<Keyboard> keys(new Keyboard());



	std::unique_ptr<FXList> fxList(new FXList());
	//fxList->getFXList()->push_back(std::shared_ptr<IFX>(new PlaybackFx(keys.get())));
	fxList->getFXList()->push_back(std::shared_ptr<IFX>(new SimpleOverdriveFx(keys.get())));

	std::thread guiThread(&Keyboard::pollForEvents, keys.get());
	std::thread pollForInput(poolForInput, fxList.get());


	std::unique_ptr<Audio> input = std::unique_ptr<Audio>(new Audio(fxList.get()));

	std::this_thread::sleep_for (std::chrono::seconds(60*4));
	//sleep(60*5);
	fxList.reset();
	//input.reset();
	keys.reset();
    return 0;
}
