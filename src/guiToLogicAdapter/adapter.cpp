/*
 * adapter.cpp
 *
 *  Created on: 17 kwi 2018
 *      Author: SF
 */

#include "adapter.hpp"

Adapter::Adapter(FXList *newFxList, IDetector *newUserInput, FxGtkList *newFxGtkList, FxGtkView *newFxGtkView, int argc, char *argv[]):
	fxList(newFxList),
	fxGtkList(newFxGtkList),
	fxGtkView(newFxGtkView),
	userInput(newUserInput),
	selectedFxNum(0),
	adapterEditFxDialog(new AdapterEditFxDialog(argc, argv, newUserInput, newFxList, &selectedFxNum))
	{
}

/*
 * fx list in audio chain
 */

void Adapter::updateFxGuiList(){
	static Gtk::TreeModel::Row row;
	int id = 1;

	fxGtkList->treeModel->clear();

	for(auto fx : *fxList->getCurrentFXList()){
		row = *(fxGtkList->treeModel->append());
		row[fxGtkList->columnsModel.idColumn] = id++;
		row[fxGtkList->columnsModel.nameColumn] = Glib::ustring(*fx->getName());
	}
}

void Adapter::selectFxInList(int indxOfFxToSelect){
	auto it = fxGtkList->treeModel->get_iter(std::to_string(indxOfFxToSelect));
	Glib::RefPtr<Gtk::TreeSelection> refTreeSelection = fxGtkList->get_selection();
	refTreeSelection->unselect_all();
	refTreeSelection->select(it);
}

void Adapter::addToSelectedFxNum(int diff){

	selectedFxNum += diff;
	if(selectedFxNum < 0){
		selectedFxNum = 0;

	}else if (selectedFxNum > fxList->getCurrentFXList()->size() - 1){
		selectedFxNum = fxList->getCurrentFXList()->size() - 1;
	}
}

/*
 * fx box with selected fx settings
 */
void Adapter::setNewFxGuiBox(int indxOfFxToUpdate){
	auto fx = fxList->getCurrentFXList()->at(indxOfFxToUpdate).get();

	fxGtkView->fxNameLabel->set_text(*fx->getName());

	//set settings in gui
	int num = 0;
	for(auto fxSetting : *(fx->getSettings())){
		auto fxBox = fxGtkView->fxSettings[num++].get();
		fxBox->show();
		fxBox->fxValueLabel->set_text(*fxSetting.getName());
		fxBox->fxValueScale->set_range(fxSetting.getMinValue(), fxSetting.getMaxValue());
		fxBox->fxValueScale->set_value(fxSetting.getValue());
	}

	//hide unused settings in gui
	for(; num <= fxGtkView->fxSettings.size(); ++num){
		fxGtkView->fxSettings[num]->hide();
	}
}

void Adapter::updateFxGuiBox(int indxOfFxToUpdate){
	auto fx = fxList->getCurrentFXList()->at(indxOfFxToUpdate).get();
	fxList->updateFXParameters(indxOfFxToUpdate);

	int num = 0;
	for(auto fxSetting : *(fx->getSettings())){
		fxGtkView->fxSettings[num].get()->fxValueScale->set_value(fxSetting.getValue());
		num++;
	}
}

void Adapter::setSelectedFxNum(int newSelectedFxNum){
	if(newSelectedFxNum > fxList->getCurrentFXList()->size() - 1){
		newSelectedFxNum = fxList->getCurrentFXList()->size() - 1;

	}else if(newSelectedFxNum < 0){
		newSelectedFxNum = 0;
	}
}


/*
 * change current active to edit settings fx
 */
void Adapter::handleUserInput(){
	userInput->getInputHandler(ControllerInput::pot1);

	updateFxGuiList();
	setNewFxGuiBox(selectedFxNum);
	selectFxInList(selectedFxNum);

	int *btn1 = userInput->getInputHandler(ControllerInput::btn1);
	int *pot1 = userInput->getInputHandler(ControllerInput::pot1);
	while(1){
		std::this_thread::sleep_for (std::chrono::milliseconds(100));

		addToSelectedFxNum(-(*pot1));

		if(*pot1 != 0){
		selectFxInList(selectedFxNum);
		setNewFxGuiBox(selectedFxNum);
		*pot1 = 0;

		//TODO add clear all pot fnc
		}

		updateFxGuiBox(selectedFxNum);

		if(*btn1){
			adapterEditFxDialog->handleEditFxDialog();
			std::this_thread::sleep_for (std::chrono::milliseconds(20));
			updateFxGuiList();
			selectFxInList(selectedFxNum);
			setNewFxGuiBox(selectedFxNum);
			std::cout<<"edit fx end"<<std::endl;
		}
	}
}
