/*
 * ncAdapterEditFx.cpp
 *
 *  Created on: 10 maj 2018
 *      Author: SF
 */

#include "ncAdapterEditFx.hpp"

std::array<char *, 5> NcAdapterEditFx::options = {
		"Cancel",
		"Add FX",
		"Move FX",
		"Remove FX"
};

NcAdapterEditFx::NcAdapterEditFx(FXList *newFxList, IDetector *newUserInput, int *newSelectedFxNum):
fxList(newFxList),
userInput(newUserInput),
selectedFxNum(newSelectedFxNum),
selectedOption(0),
optionList(new ElementListNC(std::vector<char *>{ options.begin(), options.end() }, "Select action", 20, 6, 30, 2)),
addNcDialog(new NcAdapterAddFx(newFxList, newUserInput, newSelectedFxNum))
{
	optionList->panel->showPanel();
	optionList->panel->hidePanel(); //workaround
}

void NcAdapterEditFx::addToSelectedOption(int diff){
	selectedOption += diff;
	if(selectedOption < 0){
		selectedOption = 0;

	}else if (selectedOption > 4){
		selectedOption = 4;
	}
}

void NcAdapterEditFx::handleEditFx(){

	int *pot1 = userInput->getInputHandler(ControllerInput::pot1);
	int *btn1 = userInput->getInputHandler(ControllerInput::btn1);
	if(*btn1){
		std::this_thread::sleep_for (std::chrono::milliseconds(800));
		if(*btn1){ //check if button is pressed through given time
			optionList->panel->showPanel();
			optionList->listWindow->selectFirstIndex();
			selectedOption = 0;

			while(*btn1){ //wait to stop press button
				std::this_thread::sleep_for (std::chrono::milliseconds(50));
			}

			while(!*btn1){ //stop when button pressed
				std::this_thread::sleep_for (std::chrono::milliseconds(50));

				if(*pot1 != 0){
					addToSelectedOption(-*pot1);
					optionList->listWindow->selectIndex(selectedOption);
					*pot1 = 0;
					}
				}

			while(*btn1){ //wait to stop press button
				std::this_thread::sleep_for (std::chrono::milliseconds(50));
			}

		optionList->panel->hidePanel();
		//button stop pressed
			switch (selectedOption) {

				case DialogWindowBtn::cancelBtn:
					break;

				case DialogWindowBtn::addNextBtn:
					addNcDialog->handleAddFx();
					break;

				case DialogWindowBtn::movelBtn:
//					moveFxDialog->handleMoveFxDialog();
					break;

				case DialogWindowBtn::deletelBtn:

					if(fxList->getCurrentFXList()->size() == 1){
						fxList->addFX(FxFactory::createFx(0, userInput));
					}

					fxList->removeFX(*selectedFxNum);

					*selectedFxNum = *selectedFxNum - 1;
					if (*selectedFxNum < 0){
						*selectedFxNum = 0;
					}
					break;

				default:
					break;
			}

			*btn1 = 0; //because without this selected dialog window can show again
		}
	}
}
