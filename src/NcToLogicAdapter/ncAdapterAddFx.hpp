/*
 * ncAdapterAddFx.hpp
 *
 *  Created on: 10 maj 2018
 *      Author: SF
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
