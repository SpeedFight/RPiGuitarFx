/*
 * fxListNc.hpp
 *
 *  Created on: 5 maj 2018
 *      Author: SF
 */

#ifndef FXLISTNC_HPP_
#define FXLISTNC_HPP_

#include "config.hpp"
#include <ncurses.h>
#include <panel.h>
#include <menu.h>

class FxListWindowNC{
public:
	FxListWindowNC();

	std::unique_ptr<WINDOW> *fxListWindowNC;
	std::unique_ptr<MENU> *fxMenuNC;
private:

};



#endif /* FXLISTNC_HPP_ */
