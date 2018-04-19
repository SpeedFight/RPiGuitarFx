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

#include "mainGtkView.hpp"

#include "adapter.hpp"

void poolForInput(FXList *fxList, Adapter *adapter){
	adapter->updateFxGuiList();
	adapter->setNewFxGuiBox(1);
	adapter->selectFxInList(1);

	while(1){
	fxList->updateFXParameters(1);
	adapter->updateFxGuiBox(1);
	std::this_thread::sleep_for (std::chrono::milliseconds(100));
	}
}

//tmpo help function
void printList(FXList *list){
	std::cout<<"lista: "<<std::endl;
	for(auto element : *(list->getFXList())){
		std::cout<< *(element->getName()) << std::endl;
	}
	std::cout<<std::endl;
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
	std::unique_ptr<Keyboard> keys(new Keyboard(argc, argv));

	std::unique_ptr<FXList> fxList(new FXList());

	fxList->addFX(new PlaybackFx(keys.get()));
	fxList->addFX(new SimpleOverdriveFx(keys.get()));


	std::unique_ptr<Audio> input(new Audio(fxList.get()));
	std::unique_ptr<ViewGtk> view(new ViewGtk(argc, argv));
	std::unique_ptr<Adapter> adapter(new Adapter(fxList.get(), keys.get(), view->getFxGtkList(), view->getFxGtkView()));

	std::thread guiThread(&ViewGtk::poolForView, view.get());
	std::thread keyboardInputThread(&Keyboard::pollForEvents, keys.get());
	std::thread handleUserInputThread(&Adapter::handleUserInput, adapter.get());

	std::this_thread::sleep_for (std::chrono::seconds(60*4));

	guiThread.~thread();
	keyboardInputThread.~thread();
	handleUserInputThread.~thread();

	view.reset();
	input.reset();
	fxList.reset();
	keys.reset();
    return 0;
}
