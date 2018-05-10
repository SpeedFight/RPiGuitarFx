/*
 * ncAdapter.cpp
 *
 *  Created on: 10 maj 2018
 *      Author: SF
 */

#include "ncAdapter.hpp"

NcAdapter::NcAdapter(FXList *newFxList, IDetector *newUserInput):
fxList(newFxList),
userInput(newUserInput),
selectedFxNum(0),
terminalGui(new TerminalGui()),
actualFxList(nullptr)
{
	//prepare basic UI
	fillActualFxList();
	actualFxList->panel->showPanel();
	actualFxList->panel->hidePanel();
	actualFxList->panel->showPanel(); //workaround
//
//	std::unique_ptr<ElementListNC> fxInfoBox(new ElementListNC(choices2, "Options", 20, 21, 30, 2));
//
//	std::unique_ptr<FxViewNC> fxView(new FxViewNC());
//
//	refresh();
//
//	void *bin; //because double clearing memory error :c
//	int ch;
//	while((ch = getch()) != KEY_F(1)){
//		switch(ch){
//			case 'a':
//				fxInfoBox->panel->showPanel();
//			break;
//
//			case 'b':
//				fxInfoBox->panel->hidePanel();
//				fxView->refresh();
//			break;
//
//			case KEY_DOWN:
////				optionsList->listWindow->selectByDiff(1);
////				delete fxView.get();
//				bin =  fxList.release();
////				fxInfoBox.reset(new ElementListNC(choices2, "Options", 20, 21, 30, 2));
////				fxList.reset(new ElementListNC(choices3, "FX list", 20, 24, 0, 1));
//				fxList->panel->showPanel();
//				fxList->panel->hidePanel();
//				fxList->panel->showPanel(); //workaround
////				delete bin;
//			break;
//
//			case KEY_UP:
////				optionsList->listWindow->selectByDiff(-1);
//			break;
//		}
//	}
}

void NcAdapter::fillActualFxList(){
	static std::vector<char *> fxListElements;
	void *ptr = actualFxList.release();

	fxListElements.clear();
	for(auto fx : *fxList->getFXList()){
		fxListElements.push_back((char *)fx->getName()->c_str());
	}

	actualFxList.reset(new ElementListNC(fxListElements, "FX list", 20, 24, 0, 1));
}

void NcAdapter::handleUserInput(){
	userInput->getInputHandler(ControllerInput::pot1);

//	updateFxGuiList();
//	setNewFxGuiBox(selectedFxNum);
//	selectFxInList(selectedFxNum);

	int *btn1 = userInput->getInputHandler(ControllerInput::btn1);
	int *pot1 = userInput->getInputHandler(ControllerInput::pot1);

	while(1){
		std::this_thread::sleep_for (std::chrono::milliseconds(100));

	}
}
