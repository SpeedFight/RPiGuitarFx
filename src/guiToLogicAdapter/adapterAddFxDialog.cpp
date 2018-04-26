/*
 * adapterAddFxDialog.cpp
 *
 *  Created on: 21 kwi 2018
 *      Author: SF
 */

#include "adapterAddFxDialog.hpp"

AdapterAddFxDialog::AdapterAddFxDialog(int argc, char *argv[], IDetector *newUserInput, FXList *newFxList, int *newSelectedFxNum):
	userInput(newUserInput),
	fxList(newFxList),
	selectedFxNum(newSelectedFxNum),
	addFxDialog(new DialogWindowAddFx(argc, argv)),
	selectedOptionAddFxDialog(0)
	{
	AvaibleFxList avaibleFxList(newUserInput); //object with list of all fx's
	avaibleFxAmount = 0;

	auto treeView = addFxDialog->avaibleFxGtkList;
	static Gtk::TreeModel::Row row;

	//first element of table is "cancel"
	row = *(treeView->treeModel->append());
	row[treeView->columnsModel.nameColumn] = Glib::ustring("Cancel");

	//fill rest of table with avaible fx's
	for(auto &fx : avaibleFxList.fxlist){
		avaibleFxAmount++;
		row = *(treeView->treeModel->append());
		row[treeView->columnsModel.nameColumn] = Glib::ustring(*fx->getName());
	}
}

void AdapterAddFxDialog::selectFxInList(int indxOfFxToSelect){
	auto it = addFxDialog->avaibleFxGtkList->treeModel->get_iter(std::to_string(indxOfFxToSelect));
	Glib::RefPtr<Gtk::TreeSelection> refTreeSelection = addFxDialog->avaibleFxGtkList->get_selection();
	refTreeSelection->unselect_all();
	refTreeSelection->select(it);
}

void AdapterAddFxDialog::addToSelectedFxNum(int diff){

	selectedOptionAddFxDialog += diff;
	if(selectedOptionAddFxDialog < 0){
		selectedOptionAddFxDialog = 0;

	}else if (selectedOptionAddFxDialog > avaibleFxAmount ){
		selectedOptionAddFxDialog = avaibleFxAmount;
	}
}

void AdapterAddFxDialog::handleEditFxDialog(){
//	selectedOptionAddFxDialog

	int *pot1 = userInput->getInputHandler(ControllerInput::pot1);
	int *btn1 = userInput->getInputHandler(ControllerInput::btn1);
	addFxDialog->showDialog();
	selectFxInList(selectedOptionAddFxDialog);

	while(!*btn1){ //stop when button pressed
		std::this_thread::sleep_for (std::chrono::milliseconds(100));

		addToSelectedFxNum(-(*pot1));

		if(*pot1 != 0){
			selectFxInList(selectedOptionAddFxDialog);
			*pot1 = 0;
		}
	}

	if(selectedOptionAddFxDialog > 0){
		selectedOptionAddFxDialog--;
		fxList->addFX(FxFactory::createFx(selectedOptionAddFxDialog, userInput), *selectedFxNum);
	}

	while(*btn1){ //wait to stop press button
		std::this_thread::sleep_for (std::chrono::milliseconds(100));
	}

	selectedOptionAddFxDialog = 0;
	selectFxInList(selectedOptionAddFxDialog);
	addFxDialog->hideDialog();
}
