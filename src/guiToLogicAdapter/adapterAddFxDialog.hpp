/*
 * adapterAddFxDialog.hpp
 *
 *  Created on: 21 kwi 2018
 *      Author: SF
 */

#ifndef ADAPTERADDFXDIALOG_HPP_
#define ADAPTERADDFXDIALOG_HPP_

#include "config.hpp"
#include "effectsList.hpp"
#include "effect.hpp"

#include "dialogWindowAddFx.hpp"

#include <gtkmm.h>

class AdapterAddFxDialog{
public:
	AdapterAddFxDialog(int argc, char *argv[], IDetector *userInput, FXList *newFxList, int *newSelectedFxNum);
	void handleEditFxDialog();
private:
	IDetector *userInput;
	FXList *fxList; //class contain also some other specific options for fx's
	int *selectedFxNum;
	std::unique_ptr<DialogWindowAddFx> addFxDialog; //dialog to manipulate fx list
	int selectedOptionAddFxDialog;

	void addToSelectedOptionFxListDialog(int diff);
};




#endif /* ADAPTERADDFXDIALOG_HPP_ */
