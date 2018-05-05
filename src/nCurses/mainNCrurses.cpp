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
}

TerminalGui::~TerminalGui(){
	endwin();			/* End curses mode		  */
}
