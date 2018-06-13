/*
 * ncAdapterEditFx.hpp
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

#ifndef NCADAPTEREDITFX_HPP_
#define NCADAPTEREDITFX_HPP_

#include "config.hpp"

#include <elementListNC.hpp>
#include "fxViewNC.hpp"

#include "effectsList.hpp"
#include "effect.hpp"

#include "ncAdapterAddFx.hpp"
#include "ncAdapterMoveFx.hpp"

class NcAdapterEditFx{
public:
	NcAdapterEditFx(FXList *newFxList, IDetector *newUserInput, int *newSelectedFxNum);
	void handleEditFx();

private:
	FXList *fxList; //class contain also some other specific options for fx's
	IDetector *userInput; //
	int *selectedFxNum;

	int selectedOption;
	std::unique_ptr<ElementListNC> optionList;

	static std::vector<char *> options;

	std::unique_ptr<NcAdapterAddFx> addNcDialog;
	std::unique_ptr<NcAdapterMoveFx> moveNcDialog;

	void addToSelectedOption(int diff);
};




#endif /* NCADAPTEREDITFX_HPP_ */
