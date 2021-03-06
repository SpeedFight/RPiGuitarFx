/*
 * fxListNc.cpp
 *
 *  Created on: 5 maj 2018
 *      Author: SF
 */

/*
RPiGuitarFx
Copyright (C) 2018  SpeedFight

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <listNC.hpp>
#include "string.h"


extern void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);

ListWindowNC::ListWindowNC(std::vector<char *> newElements, std::string title, int newWindowWidth, int newWindowHeight, int newWindowPosX, int newWindowPosY):
		windowWidth(newWindowWidth  ),
		windowHeight(newWindowHeight ),
		windowPosX(newWindowPosX   ),
		windowPosY(newWindowPosY   ),
		fxListWindowNC(newwin(newWindowHeight, newWindowWidth, newWindowPosY, newWindowPosX)),
		fxMenuNC(nullptr)
	{


	listOfElements.reserve(10);

	/* Crate menu */
	fxMenuNC.reset(new_menu(&listOfElements.front()));
	for(auto &element : newElements){
		listOfElements.push_back(new_item((char *)element,""));
	}
	fxMenuNC.reset(new_menu(&listOfElements.front()));

	/* Create the window to be associated with the menu */
//	keypad(fxListWindowNC.get(), TRUE);

	/* Set main window and sub window */
	set_menu_win(fxMenuNC.get(), fxListWindowNC.get());
	set_menu_sub(fxMenuNC.get(), derwin(fxListWindowNC.get(), windowHeight - 2, windowWidth - 2, 1, 1));
	set_menu_format(fxMenuNC.get(), windowHeight - 2, 1);

	/* Print a border around the main window and print a title */
	box(fxListWindowNC.get(), 0, 0);
	print_in_middle(fxListWindowNC.get(), 0, 0, windowWidth, (char*)title.c_str(), COLOR_PAIR(1));

	/* Post the menu */
	post_menu(fxMenuNC.get());
	refreshWindow();

//	int c;
//	while((c = wgetch(fxListWindowNC.get())) != KEY_F(1))
//	{
//		switch(c){
//			case KEY_DOWN:
//				menu_driver(fxMenuNC.get(), REQ_DOWN_ITEM);
//				break;
//
//			case KEY_UP:
//				menu_driver(fxMenuNC.get(), REQ_UP_ITEM);
//				break;
//		}
//		refreshWindow();
//	}

}

ListWindowNC::~ListWindowNC(){
	/* Unpost and free all the memory taken up */
	unpost_menu(fxMenuNC.get());
	free_menu(fxMenuNC.get());
	clearList();
	delwin(fxListWindowNC.get());
	refresh();
}

void ListWindowNC::selectFirstIndex(){
	menu_driver(fxMenuNC.get(), REQ_FIRST_ITEM);
	refreshWindow();
}

void ListWindowNC::selectIndex(unsigned int newIndex){
	selectByDiff(newIndex - getSelectedIndex());
}

void ListWindowNC::selectByDiff(int diff){
	if(diff > 0){
		for (; diff > 0; --diff) {
			menu_driver(fxMenuNC.get(), REQ_DOWN_ITEM);
		}
	}else if (diff < 0){
		for (; diff < 0; ++diff) {
			menu_driver(fxMenuNC.get(), REQ_UP_ITEM);
		}
	}
	refreshWindow();
}

void ListWindowNC::setNewList(std::vector<char *> newElements){
	unpost_menu(fxMenuNC.get());
	free_menu(fxMenuNC.get());
	clearList();
	listOfElements.clear();
	for(auto &element : newElements){
		listOfElements.push_back(new_item((char *)element,""));
	}
	fxMenuNC.reset(new_menu(&listOfElements.front()));
	set_menu_win(fxMenuNC.get(), fxListWindowNC.get());
	set_menu_format(fxMenuNC.get(), windowHeight - 4, 1);
	post_menu(fxMenuNC.get());
	selectFirstIndex();
}

void ListWindowNC::clearList(){
	for(auto &element : listOfElements){
		free_item(element);
	}
}

int ListWindowNC::getSelectedIndex(){
	return current_item(fxMenuNC.get())->index;
}

void ListWindowNC::refreshWindow(){
	wrefresh(fxListWindowNC.get());
}
