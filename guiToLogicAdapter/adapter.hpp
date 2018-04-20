/*
 * adapter.hpp
 *
 *  Created on: 17 kwi 2018
 *      Author: SF
 */

#ifndef ADAPTER_HPP_
#define ADAPTER_HPP_

#include "config.hpp"
#include "mainGtkView.hpp"
#include "fxGtkView.hpp"
#include "fxGtkList.hpp"
#include "dialogWindow.hpp"

#include "effectsList.hpp"
#include "effect.hpp"

#include <gtkmm.h>

class Adapter{
public:
	Adapter(FXList *newFxList, IDetector *newUserInput, FxGtkList *newFxGtkList, FxGtkView *newFxGtkView);
	void setNewFxList(FXList *newFxList);
	void updateFxGuiList();
	void setNewFxGuiBox(int indxOfFxToUpdate);
	void updateFxGuiBox(int indxOfFxToUpdate);
	void selectFxInList(int indxOfFxToSelect);
	void handleUserInput();

private:
	FXList *fxList; //class contain also some other specific options for fx's
	FxGtkList *fxGtkList; //gui list of fx
	FxGtkView *fxGtkView; //gui box where is all effect options
	IDetector *userInput; //
	int selectedFxNum;

	void setSelectedFxNum(int newSelectedFxNum);
	void addToSelectedFxNum(int diff);
};



#endif /* ADAPTER_HPP_ */
