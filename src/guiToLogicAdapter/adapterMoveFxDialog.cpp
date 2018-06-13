/*
 * adapterMoveFxDialog.cpp
 *
 *  Created on: 21 kwi 2018
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

#include "adapterMoveFxDialog.hpp"

AdapterMoveFxDialog::AdapterMoveFxDialog(int argc, char *argv[], IDetector *newUserInput, FXList *newFxList, int *newSelectedFxNum):
	userInput(newUserInput),
	fxList(newFxList),
	selectedFxNum(newSelectedFxNum),
	moveFxDialog(new DialogWindowMoveFx(argc, argv)),
	selectedOptionMoveFxDialog(0)
	{
//	AvaibleFxList avaibleFxList(newUserInput); //object with list of all fx's

//	auto treeView = moveFxDialog->actualFxGtkList;
//	static Gtk::TreeModel::Row row;

	//fill table with actual fx's
//	for(auto &fx : fxList->getCurrentFXList()){
//		row = *(treeView->treeModel->append());
//		row[treeView->columnsModel.nameColumn] = Glib::ustring(*fx->getName());
//	}
	reloadFxList();
}

void AdapterMoveFxDialog::reloadFxList(){
	auto treeView = moveFxDialog->actualFxGtkList;
	treeView->treeModel->clear();
	static Gtk::TreeModel::Row row;

	//fill table with actual fx's
	for(auto fx : *fxList->getCurrentFXList()){
		row = *(treeView->treeModel->append());
		row[treeView->columnsModel.nameColumn] = Glib::ustring(*fx->getName());
	}

}

void AdapterMoveFxDialog::selectFxInList(int indxOfFxToSelect){
	auto it = moveFxDialog->actualFxGtkList->treeModel->get_iter(std::to_string(indxOfFxToSelect));
	Glib::RefPtr<Gtk::TreeSelection> refTreeSelection = moveFxDialog->actualFxGtkList->get_selection();
	refTreeSelection->unselect_all();
	refTreeSelection->select(it);
}

void AdapterMoveFxDialog::addToSelectedFxNum(int diff){

	selectedOptionMoveFxDialog += diff;
	if(selectedOptionMoveFxDialog < 0){
		selectedOptionMoveFxDialog = 0;

	}else if (selectedOptionMoveFxDialog > fxList->getCurrentFXList()->size() - 1){
		selectedOptionMoveFxDialog = fxList->getCurrentFXList()->size() -1;
	}
}

void AdapterMoveFxDialog::handleMoveFxDialog(){
//	selectedOptionAddFxDialog

	int *pot1 = userInput->getInputHandler(ControllerInput::pot1);
	int *btn1 = userInput->getInputHandler(ControllerInput::btn1);

	selectedOptionMoveFxDialog = *selectedFxNum;
	reloadFxList();

	moveFxDialog->showDialog();
	selectFxInList(selectedOptionMoveFxDialog);

	while(!*btn1){ //stop when button pressed
		std::this_thread::sleep_for (std::chrono::milliseconds(100));


		if(*pot1 != 0){
			addToSelectedFxNum(-(*pot1));

			if(*selectedFxNum == selectedOptionMoveFxDialog){
				*pot1 = 0;
				continue;
			}

			fxList->moveFX(*selectedFxNum, selectedOptionMoveFxDialog);
			*selectedFxNum = selectedOptionMoveFxDialog;

			std::this_thread::sleep_for (std::chrono::milliseconds(20));
			reloadFxList();
			selectFxInList(selectedOptionMoveFxDialog);
			*pot1 = 0;
		}
	}

	while(*btn1){ //wait to stop press button
		std::this_thread::sleep_for (std::chrono::milliseconds(100));
	}

	//selectFxInList(selectedOptionAddFxDialog);
	moveFxDialog->hideDialog();
}
