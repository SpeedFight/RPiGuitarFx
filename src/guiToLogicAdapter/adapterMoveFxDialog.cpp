/*
 * adapterMoveFxDialog.cpp
 *
 *  Created on: 21 kwi 2018
 *      Author: SF
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
			fxList->moveFX(*selectedFxNum, selectedOptionMoveFxDialog);
			*selectedFxNum = selectedOptionMoveFxDialog;

			std::this_thread::sleep_for (std::chrono::milliseconds(100));
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
