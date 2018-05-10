/*
 * ncAdapterEditFx.hpp
 *
 *  Created on: 10 maj 2018
 *      Author: SF
 */

#ifndef NCADAPTEREDITFX_HPP_
#define NCADAPTEREDITFX_HPP_

#include "config.hpp"

#include <elementListNC.hpp>
#include "fxViewNC.hpp"

#include "effectsList.hpp"
#include "effect.hpp"

class NcAdapterEditFx{
public:
	NcAdapterEditFx(FXList *newFxList, IDetector *newUserInput, int *newSelectedFxNum);
	void handleEditFx();

private:
	FXList *fxList; //class contain also some other specific options for fx's
	IDetector *userInput; //
	int *selectedFxNum;
};




#endif /* NCADAPTEREDITFX_HPP_ */
