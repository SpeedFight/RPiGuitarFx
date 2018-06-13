/*
 * adapterEditFxDialog.hpp
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

#ifndef ADAPTEREDITFXDIALOG_HPP_
#define ADAPTEREDITFXDIALOG_HPP_

#include "config.hpp"
#include "effectsList.hpp"
#include "effect.hpp"

#include "dialogWindowFxList.hpp"
#include "dialogWindowAddFx.hpp"

#include "adapterAddFxDialog.hpp"
#include "adapterMoveFxDialog.hpp"

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
	std::unique_ptr<AdapterMoveFxDialog> moveFxDialog; //dialog to add new fx

	void addToSelectedOptionFxListDialog(int diff);
};

#endif /* ADAPTEREDITFXDIALOG_HPP_ */
