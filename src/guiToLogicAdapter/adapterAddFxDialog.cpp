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

	auto treeView = addFxDialog->avaibleFxGtkList;
	static Gtk::TreeModel::Row row;

	//first element of table is "cancel"
	row = *(treeView->treeModel->append());
	row[treeView->columnsModel.nameColumn] = Glib::ustring("Cancel");

	//fill rest of table with avaible fx's
	for(auto &fx : avaibleFxList.fxlist){
		row = *(treeView->treeModel->append());
		row[treeView->columnsModel.nameColumn] = Glib::ustring(*fx->getName());
	}
}

void AdapterAddFxDialog::handleEditFxDialog(){
	//error when use showDialog
	std::cout<<"1"<<std::endl;
	addFxDialog->showDialog();
	std::cout<<"2"<<std::endl;
	std::this_thread::sleep_for (std::chrono::milliseconds(1000));
	std::cout<<"3"<<std::endl;
	addFxDialog->hideDialog();
	std::cout<<"4"<<std::endl;
	int *btn1 = userInput->getInputHandler(ControllerInput::btn1);
	int *pot5 = userInput->getInputHandler(ControllerInput::pot5);
}
