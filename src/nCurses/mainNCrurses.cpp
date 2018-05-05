/*
 * mainNCrurses.cpp
 *
 *  Created on: 4 maj 2018
 *      Author: SF
 */

#include "mainNCrurses.hpp"




TerminalGui::TerminalGui(){
	initscr();
	cbreak();
	noecho();
	std::unique_ptr<FxListWindowNC> fxList(new FxListWindowNC());
	refresh();

//	fxList->fxListWindowNC->get()->




	while(1){

	}
}

TerminalGui::~TerminalGui(){
	endwin();			/* End curses mode		  */
}


