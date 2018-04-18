/*
 * adapter.hpp
 *
 *  Created on: 17 kwi 2018
 *      Author: SF
 */

#ifndef ADAPTER_HPP_
#define ADAPTER_HPP_

#include "config.hpp"
#include "mainGtkView.hpp"
#include "fxGtkView.hpp"
#include "fxGtkList.hpp"

#include "effectsList.hpp"
#include "effect.hpp"

#include <gtkmm.h>

class Adapter{
public:
	Adapter(FxGtkList *newFxGtkList, FxGtkView *newFxGtkView);
	void updateFxGuiList(FXList *fxList);
	void setNewFxGuiBox(FXList *fxList, int indxOfFxToUpdate);

private:
	FxGtkList *fxGtkList; //gui list of fx
	FxGtkView *fxGtkView; //gui box where is all effect options

};



#endif /* ADAPTER_HPP_ */
