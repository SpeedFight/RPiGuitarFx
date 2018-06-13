/*
 * ncAdapter.hpp
 *
 *  Created on: 10 maj 2018
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

#ifndef NCADAPTER_HPP_
#define NCADAPTER_HPP_

#include "config.hpp"

#include <elementListNC.hpp>
#include "fxViewNC.hpp"
#include "mainNCrurses.hpp"

#include "effectsList.hpp"
#include "effect.hpp"

#include "ncAdapterEditFx.hpp"

class NcAdapter{
public:
	NcAdapter(FXList *newFxList, IDetector *newUserInput);
	void handleUserInput();


private:
	void fillActualFxList();
	void addToSelectedFxNum(int diff);
	void setNewFxGuiBox();
	void updateFxGuiBox();


	FXList *fxList; //class contain also some other specific options for fx's
	IDetector *userInput; //
	int selectedFxNum;
	std::unique_ptr<TerminalGui> terminalGui;
	std::unique_ptr<ElementListNC> actualFxList;
	std::unique_ptr<FxViewNC> fxViewNc;
	std::unique_ptr<NcAdapterEditFx> editNcDialog;

};



#endif /* NCADAPTER_HPP_ */
