/*
 * adapterAddFxDialog.hpp
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
	void handleAddFxDialog();
private:
	IDetector *userInput;
	FXList *fxList; //class contain also some other specific options for fx's
	int *selectedFxNum;
	std::unique_ptr<DialogWindowAddFx> addFxDialog; //dialog to manipulate fx list
	int selectedOptionAddFxDialog;
	int avaibleFxAmount;

	void addToSelectedOptionFxListDialog(int diff);
	void selectFxInList(int indxOfFxToSelect);
	void addToSelectedFxNum(int diff);

};




#endif /* ADAPTERADDFXDIALOG_HPP_ */
