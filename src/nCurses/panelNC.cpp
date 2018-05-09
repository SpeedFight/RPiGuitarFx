/*
 * panelNC.cpp
 *
 *  Created on: 7 maj 2018
 *      Author: SF
 */
#include "panelNC.hpp"


PanelNC::PanelNC(WINDOW *newWindow, int newWindowWidth, int newWindowHeight, int newWindowPosX, int newWindowPosY):
		windowWidth(newWindowWidth  ),
		windowHeight(newWindowHeight ),
		windowPosX(newWindowPosX   ),
		windowPosY(newWindowPosY   ),
		isShow(false)
			{

	/* Initialize all the colors */
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);

	window = newWindow;
	panel.reset(new_panel(window)); 	/* Push 0, order: stdscr-0 */
	update_panels();

	hide_panel(panel.get());
	doupdate();

//	int ch;
//	while((ch = getch()) != KEY_F(1))
//	{	switch(ch)
//		{	case 'a':
//				if(isShow)
//				{	hide_panel(panel.get());
//					isShow = false;
//				}
//				else
//				{	show_panel(panel.get());
//					isShow = true;
//				}
//				break;
//		}
//		update_panels();
//		doupdate();
//	}

}

PanelNC::~PanelNC(){

}

void PanelNC::hidePanel(){
	if(isShow){
		hide_panel(panel.get());
		isShow = false;
		update_panels();
		doupdate();
	}
}

void PanelNC::showPanel(){
	if(!isShow){
		show_panel(panel.get());
		isShow = true;
		update_panels();
		doupdate();
	}
}
