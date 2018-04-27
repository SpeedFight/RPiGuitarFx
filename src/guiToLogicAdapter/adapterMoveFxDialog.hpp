/*
 * adapterMoveFxDialog.hpp
 *
 *  Created on: 21 kwi 2018
 *      Author: SF
 */

#ifndef ADAPTERMOVEFXDIALOG_HPP_
#define ADAPTERMOVEFXDIALOG_HPP_

#include "config.hpp"
#include "effectsList.hpp"
#include "effect.hpp"

#include "dialogWindowMoveFx.hpp"

#include <gtkmm.h>

class AdapterMoveFxDialog{
public:
	AdapterMoveFxDialog(int argc, char *argv[], IDetector *userInput, FXList *newFxList, int *newSelectedFxNum);
	void handleMoveFxDialog();
private:
	IDetector *userInput;
	FXList *fxList; //class contain also some other specific options for fx's
	int *selectedFxNum;
	std::unique_ptr<DialogWindowMoveFx> moveFxDialog; //dialog to manipulate fx list
	int selectedOptionMoveFxDialog;

	void addToSelectedFxNum(int diff);
	void selectFxInList(int indxOfFxToSelect);
	void reloadFxList();

};



#endif /* ADAPTERMOVEFXDIALOG_HPP_ */
