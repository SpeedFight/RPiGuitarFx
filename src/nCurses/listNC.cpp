/*
 * fxListNc.cpp
 *
 *  Created on: 5 maj 2018
 *      Author: SF
 */

#include <listNC.hpp>
#include "string.h"

std::vector<char *> choices1 = {
						"Choice 0",
                        "Choice 1",
                        "Choice 2",
                        "Choice 3",
                        "Choice 4",
						"Choice 5",
						"Choice 6",
						"Choice 7",
						"Choice 8",
                        "Exit"
                  };

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

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}

ListWindowNC::ListWindowNC(int newWindowWidth, int newWindowHeight, int newWindowPosX, int newWindowPosY):
		windowWidth(newWindowWidth  ),
		windowHeight(newWindowHeight ),
		windowPosX(newWindowPosX   ),
		windowPosY(newWindowPosY   ),
		fxListWindowNC(newwin(windowHeight, windowWidth, windowPosY, windowPosX)),
		fxMenuNC(nullptr)
	{
	std::string title = "List";

	start_color();;
	init_pair(1, COLOR_CYAN, COLOR_BLACK);

	listOfElements.reserve(10);

//	setNewList(choices1);
	/* Crate menu */
//	fxMenuNC.reset(new_menu(&listOfElements.front()));

	/* Create the window to be associated with the menu */
	keypad(fxListWindowNC.get(), TRUE);

	/* Set main window and sub window */
//	set_menu_win(fxMenuNC.get(), fxListWindowNC.get());
	set_menu_sub(fxMenuNC.get(), derwin(fxListWindowNC.get(), windowHeight - 4, windowWidth - 2, 3, 1));
//	set_menu_format(fxMenuNC.get(), windowHeight - 4, 1);

	/* Print a border around the main window and print a title */
	box(fxListWindowNC.get(), 0, 0);
	print_in_middle(fxListWindowNC.get(), 1, 0, windowWidth, (char*)title.c_str(), COLOR_PAIR(1));
	/* Print line under title */
	mvwaddch(fxListWindowNC.get(), 2, 0, ACS_LTEE);
	mvwhline(fxListWindowNC.get(), 2, 1, ACS_HLINE, 18);
	mvwaddch(fxListWindowNC.get(), 2, windowWidth - 1, ACS_RTEE);
	refresh();

	/* Post the menu */
//	post_menu(fxMenuNC.get());
//	refreshWindow();

	int c;
	while((c = wgetch(fxListWindowNC.get())) != KEY_F(1))
	{
		switch(c){
			case KEY_DOWN:
				menu_driver(fxMenuNC.get(), REQ_DOWN_ITEM);
				break;

			case KEY_UP:
				menu_driver(fxMenuNC.get(), REQ_UP_ITEM);
				setNewList(choices2);
				break;
		}
		refreshWindow();
	}

}

ListWindowNC::~ListWindowNC(){
	/* Unpost and free all the memory taken up */
	unpost_menu(fxMenuNC.get());
	free_menu(fxMenuNC.get());
	clearList();
	endwin();
}

inline void ListWindowNC::selectFirstIndex(){
	menu_driver(fxMenuNC.get(), REQ_FIRST_ITEM);
	refreshWindow();
}

inline void ListWindowNC::selectIndex(unsigned int newIndex){
	selectByDiff(newIndex - getSelectedIndex());
}

inline void ListWindowNC::selectByDiff(int diff){
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

inline void ListWindowNC::setNewList(std::vector<char *> newElements){
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

inline void ListWindowNC::clearList(){
	for(auto &element : listOfElements){
		free_item(element);
	}
}

inline int ListWindowNC::getSelectedIndex(){
	return current_item(fxMenuNC.get())->index;
}

inline void ListWindowNC::refreshWindow(){
	wrefresh(fxListWindowNC.get());
}
