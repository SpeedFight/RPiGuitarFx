/*
 * mainNCrurses.hpp
 *
 *  Created on: 4 maj 2018
 *      Author: SF
 */

#ifndef MAINNCRURSES_HPP_
#define MAINNCRURSES_HPP_

//#include <listNC.hpp>
//#include "panelNC.hpp"
#include "elementNC.hpp"
#include "config.hpp"

#include <ncurses.h>
#include <menu.h>
#include <panel.h>

class TerminalGui{
public:
	TerminalGui();
	~TerminalGui();

	void poolForView();
private:



};



#endif /* MAINNCRURSES_HPP_ */
