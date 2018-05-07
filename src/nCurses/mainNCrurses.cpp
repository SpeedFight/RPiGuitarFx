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
//	std::unique_ptr<ListWindowNC> fxList(new ListWindowNC(20, 8, 0, 2));
	std::unique_ptr<PanelNC> fxList(new PanelNC(20, 8, 20, 4));
	refresh();

	while(1){

	}
}

TerminalGui::~TerminalGui(){
	endwin();			/* End curses mode		  */
}


