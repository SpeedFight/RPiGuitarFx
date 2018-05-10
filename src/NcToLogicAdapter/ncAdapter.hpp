/*
 * ncAdapter.hpp
 *
 *  Created on: 10 maj 2018
 *      Author: SF
 */

#ifndef NCADAPTER_HPP_
#define NCADAPTER_HPP_

#include "config.hpp"

#include <elementListNC.hpp>
#include "fxViewNC.hpp"
#include "mainNCrurses.hpp"

#include "effectsList.hpp"
#include "effect.hpp"

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

};



#endif /* NCADAPTER_HPP_ */
