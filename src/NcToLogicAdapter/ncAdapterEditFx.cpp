/*
 * ncAdapterEditFx.cpp
 *
 *  Created on: 10 maj 2018
 *      Author: SF
 */

/*
RPiGuitarFx
Copyright (C) 2018  SpeedFight

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ncAdapterEditFx.hpp"

std::vector<char *> NcAdapterEditFx::options = {
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
addNcDialog(new NcAdapterAddFx(newFxList, newUserInput, newSelectedFxNum)),
moveNcDialog(new NcAdapterMoveFx(newFxList, newUserInput, newSelectedFxNum))
{
	int width = (options.size() + 2 > 21) ? 21 : options.size() + 2;
	optionList.reset(new ElementListNC(options, "Select action", 20, width, 30, 2));

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
					moveNcDialog->handleMoveFx();
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
