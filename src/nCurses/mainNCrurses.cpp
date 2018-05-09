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

	//int windowWidth, int windowHeight, int windowPosX, int windowPosY

	std::unique_ptr<ElementListNC> elementListFx(new ElementListNC(choices2, "lista", 20, 20, 0, 1));
	refresh();

	int ch;
	while((ch = getch()) != KEY_F(1))
	{	switch(ch){
			case 'a':
				elementListFx->panel->showPanel();
			break;

			case 'b':
				elementListFx->panel->hidePanel();
			break;

			case KEY_DOWN:
				elementListFx->listWindow->selectByDiff(1);
			break;

			case KEY_UP:
				elementListFx->listWindow->selectByDiff(-1);
			break;
		}
	}

	while(1){

	}
}

TerminalGui::~TerminalGui(){
	endwin();			/* End curses mode		  */
}


