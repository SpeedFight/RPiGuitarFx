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
	curs_set(0); //invisible cursor
	keypad(stdscr, TRUE);

	/* Initialize all the colors */
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);

	//int windowWidth, int windowHeight, int windowPosX, int windowPosY

//	std::unique_ptr<ElementListNC> fxList(new ElementListNC(choices2, "FX list", 20, 24, 0, 1));
//	fxList->panel->showPanel();
//	fxList->panel->hidePanel();
//	fxList->panel->showPanel(); //workaround
//
//	std::unique_ptr<ElementListNC> fxInfoBox(new ElementListNC(choices2, "Options", 20, 21, 30, 2));
//
//	std::unique_ptr<FxViewNC> fxView(new FxViewNC());
//
//	refresh();

//	void *bin; //because double clearing memory error :c
//	int ch;
//	while((ch = getch()) != KEY_F(1)){
//		switch(ch){
//			case 'a':
//				fxInfoBox->panel->showPanel();
//			break;
//
//			case 'b':
//				fxInfoBox->panel->hidePanel();
//				fxView->refresh();
//			break;
//
//			case KEY_DOWN:
////				optionsList->listWindow->selectByDiff(1);
////				delete fxView.get();
//				bin =  fxList.release();
////				fxInfoBox.reset(new ElementListNC(choices2, "Options", 20, 21, 30, 2));
//				fxList.reset(new ElementListNC(choices3, "FX list", 20, 24, 0, 1));
//				fxList->panel->showPanel();
//				fxList->panel->hidePanel();
//				fxList->panel->showPanel(); //workaround
////				delete bin;
//			break;
//
//			case KEY_UP:
////				optionsList->listWindow->selectByDiff(-1);
//			break;
//		}
//	}
}

TerminalGui::~TerminalGui(){
	endwin();			/* End curses mode		  */
}


