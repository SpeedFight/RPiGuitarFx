/*
 * adapterMoveFxDialog.hpp
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
