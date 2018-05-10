/*
 * ncAdapterMoveFx.hpp
 *
 *  Created on: 10 maj 2018
 *      Author: SF
 */

#ifndef NCADAPTERMOVEFX_HPP_
#define NCADAPTERMOVEFX_HPP_

#include "config.hpp"

#include <elementListNC.hpp>
#include "fxViewNC.hpp"

#include "effectsList.hpp"
#include "effect.hpp"

class NcAdapterMoveFx{
public:
	NcAdapterMoveFx(FXList *newFxList, IDetector *newUserInput, int *newSelectedFxNum);
	void handleMoveFx();

private:
	FXList *fxList; //class contain also some other specific options for fx's
	IDetector *userInput; //
	int *selectedFxNum;

	int selectedOption;
	std::unique_ptr<ElementListNC> actualFxList;

	static std::vector<char *> options;
	int avaibleFxAmount;

	void addToSelectedOption(int diff);
	void fillActualFxList();
};

#endif /* NCADAPTERMOVEFX_HPP_ */
