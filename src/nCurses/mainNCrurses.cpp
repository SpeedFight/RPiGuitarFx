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
	keypad(stdscr, TRUE);
	std::unique_ptr<FxListWindowNC> fxList(new FxListWindowNC(20, 8, 0, 2));
	refresh();

	while(1){

	}
}

TerminalGui::~TerminalGui(){
	endwin();			/* End curses mode		  */
}


