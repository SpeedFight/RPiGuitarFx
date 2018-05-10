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
actualFxList(nullptr),
fxViewNc(nullptr)
{
	//prepare basic UI
	fillActualFxList();

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
	fxViewNc.reset(new FxViewNC());

	fxListElements.clear();
	for(auto fx : *fxList->getCurrentFXList()){
		fxListElements.push_back((char *)fx->getName()->c_str());
	}

	actualFxList.reset(new ElementListNC(fxListElements, "FX list", 20, 24, 0, 1));
	actualFxList->panel->showPanel();
	actualFxList->panel->hidePanel();
	actualFxList->panel->showPanel(); //workaround
}

void NcAdapter::addToSelectedFxNum(int diff){

	selectedFxNum += diff;
	if(selectedFxNum < 0){
		selectedFxNum = 0;

	}else if (selectedFxNum > fxList->getCurrentFXList()->size() - 1){
		selectedFxNum = fxList->getCurrentFXList()->size() - 1;
	}
}

void NcAdapter::setNewFxGuiBox(){
	fxViewNc->eraseWin();
	void *ptr = fxViewNc.release();
	fxViewNc.reset(new FxViewNC());

	auto currentFx = fxList->getCurrentFXList()->at(selectedFxNum);

	fxViewNc->fxInfoBox.reset(new FxInfoViewNC((char *)currentFx->getName()->c_str(), 1, 60, 5, 20, 4));

	short x;
	short y;
	int i = 0;
	for (auto fxSetting : *(currentFx->getSettings())) {
		x = (i % 3 + 1) * 20;
		y = (i < 3) ? 13 : 19;

		fxViewNc->settingsBoxs[i].reset(new FxSettingViewNC(*fxSetting.getName(), std::to_string(fxSetting.getValue()), 20, 6, x, y));

		++i;
	}

	fxViewNc->refresh();
}

void NcAdapter::updateFxGuiBox(){
	auto currentFx = fxList->getCurrentFXList()->at(selectedFxNum);
	currentFx.get()->updateSettings();

	int i = 0;
	for (auto fxSetting : *(currentFx->getSettings())) {
		if(fxViewNc->settingsBoxs[i]){
			fxViewNc->settingsBoxs[i]->updateValue(std::to_string(fxSetting.getValue()));
			++i;
		}
	}
}

//refreshFxGuiBox

void NcAdapter::handleUserInput(){
	int *btn1 = userInput->getInputHandler(ControllerInput::btn1);
	int *pot1 = userInput->getInputHandler(ControllerInput::pot1);

	setNewFxGuiBox();
	while(1){
		std::this_thread::sleep_for (std::chrono::milliseconds(100));


		if(*pot1 != 0){
			addToSelectedFxNum(-(*pot1));

			actualFxList->listWindow->selectIndex(selectedFxNum);
			setNewFxGuiBox();
			*pot1 = 0;
		}

		if(*btn1){
//			adapterEditFxDialog->handleEditFxDialog();
			std::this_thread::sleep_for (std::chrono::milliseconds(50));
//			updateFxGuiList();
//			selectFxInList(selectedFxNum);
//			setNewFxGuiBox(selectedFxNum);
//			std::cout<<"edit fx end"<<std::endl;

			setNewFxGuiBox();
			actualFxList->listWindow->selectIndex(selectedFxNum);
		}

		updateFxGuiBox();
	}
}
