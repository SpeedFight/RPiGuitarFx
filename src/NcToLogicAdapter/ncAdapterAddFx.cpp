/*
 * ncAdapterAddFx.cpp
 *
 *  Created on: 10 maj 2018
 *      Author: SF
 */

#include "ncAdapterAddFx.hpp"

NcAdapterAddFx::NcAdapterAddFx(FXList *newFxList, IDetector *newUserInput, int *newSelectedFxNum):
fxList(newFxList),
userInput(newUserInput),
selectedFxNum(newSelectedFxNum),
selectedOption(0),
optionList(nullptr)
{
	AvaibleFxList avaibleFxList(newUserInput); //object with list of all fx's
	avaibleFxAmount = 0;

	std::vector<char *> avaibleFxNames;
	avaibleFxNames.reserve(10);

	avaibleFxNames.push_back("Cancel");
	for(auto &fx : avaibleFxList.fxlist){
		avaibleFxNames.push_back((char *)fx->getName()->c_str());
		avaibleFxAmount++;
	}

	int width = (avaibleFxNames.size() + 2 > 21) ? 21 : avaibleFxNames.size() + 2;
	optionList.reset(new ElementListNC(avaibleFxNames, "Add FX", 20, width, 30, 2));


	optionList->panel->showPanel();
	optionList->panel->hidePanel(); //workaround
}

void NcAdapterAddFx::addToSelectedOption(int diff){

	selectedOption += diff;
	if(selectedOption < 0){
		selectedOption = 0;

	}else if (selectedOption > avaibleFxAmount ){
		selectedOption = avaibleFxAmount;
	}
}

void NcAdapterAddFx::handleAddFx(){
	int *pot1 = userInput->getInputHandler(ControllerInput::pot1);
	int *btn1 = userInput->getInputHandler(ControllerInput::btn1);

	optionList->panel->showPanel();
	optionList->listWindow->selectFirstIndex();
	selectedOption = 0;

	while(!*btn1){ //stop when button pressed
		std::this_thread::sleep_for (std::chrono::milliseconds(50));


		if(*pot1 != 0){
			addToSelectedOption(-(*pot1));
			optionList->listWindow->selectIndex(selectedOption);
			*pot1 = 0;
		}
	}

	if(selectedOption > 0){
		selectedOption--;
		fxList->addFX(FxFactory::createFx(selectedOption, userInput), *selectedFxNum);
	}

	while(*btn1){ //wait to stop press button
		std::this_thread::sleep_for (std::chrono::milliseconds(100));
	}

//	selectFxInList(selectedOptionAddFxDialog);
	optionList->panel->hidePanel();
}
