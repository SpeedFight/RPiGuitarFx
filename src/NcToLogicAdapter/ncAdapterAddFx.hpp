/*
 * ncAdapterAddFx.hpp
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

#ifndef NCADAPTERADDFX_HPP_
#define NCADAPTERADDFX_HPP_

#include "config.hpp"

#include <elementListNC.hpp>
#include "fxViewNC.hpp"

#include "effectsList.hpp"
#include "effect.hpp"

class NcAdapterAddFx{
public:
	NcAdapterAddFx(FXList *newFxList, IDetector *newUserInput, int *newSelectedFxNum);
	void handleAddFx();

private:
	FXList *fxList; //class contain also some other specific options for fx's
	IDetector *userInput; //
	int *selectedFxNum;

	int selectedOption;
	std::unique_ptr<ElementListNC> optionList;

	static std::vector<char *> options;
	int avaibleFxAmount;

	void addToSelectedOption(int diff);
};


#endif /* NCADAPTERADDFX_HPP_ */
