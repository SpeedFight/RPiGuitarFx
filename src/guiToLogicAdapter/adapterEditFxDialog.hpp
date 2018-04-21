/*
 * adapterEditFxDialog.hpp
 *
 *  Created on: 21 kwi 2018
 *      Author: SF
 */

#ifndef ADAPTEREDITFXDIALOG_HPP_
#define ADAPTEREDITFXDIALOG_HPP_

#include "config.hpp"
#include "effectsList.hpp"
#include "effect.hpp"

#include "dialogWindowFxList.hpp"
#include "dialogWindowAddFx.hpp"

#include "adapterAddFxDialog.hpp"

#include <gtkmm.h>

class AdapterEditFxDialog{
public:
	AdapterEditFxDialog(int argc, char *argv[], IDetector *userInput, FXList *newFxList, int *newSelectedFxNum);
	void handleEditFxDialog();


private:
	IDetector *userInput;
	FXList *fxList; //class contain also some other specific options for fx's
	int *selectedFxNum;
	std::unique_ptr<DialogWindowFxList> fxDialog; //dialog to manipulate fx list
	int selectedOptionFxListDialog;
	std::unique_ptr<AdapterAddFxDialog> addFxDialog; //dialog to add new fx

	void addToSelectedOptionFxListDialog(int diff);
};

#endif /* ADAPTEREDITFXDIALOG_HPP_ */
