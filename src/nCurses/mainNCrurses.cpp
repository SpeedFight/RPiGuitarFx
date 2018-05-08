/*
 * mainNCrurses.cpp
 *
 *  Created on: 4 maj 2018
 *      Author: SF
 */

#include "mainNCrurses.hpp"

std::vector<char *> choices2 = {
						"wybor 0",
                        "wybor 1",
                        "wybor 2",
                        "wybor 3",
                        "wybor 4",
						"wybor 5",
						"wybor 6",
						"wybor 7",
						"wybor 8",
                        "Exit"
                  };


TerminalGui::TerminalGui(){
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	/* Initialize all the colors */
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);

	std::unique_ptr<ListWindowNC> fxList(new ListWindowNC(choices2, "lista", 20, 8, 6, 6));
	std::unique_ptr<PanelNC> panel(new PanelNC(fxList->fxListWindowNC.get(), 20, 8, 20, 4));
	refresh();

	while(1){

	}
}

TerminalGui::~TerminalGui(){
	endwin();			/* End curses mode		  */
}


