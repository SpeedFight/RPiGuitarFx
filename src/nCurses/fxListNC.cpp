/*
 * fxListNc.cpp
 *
 *  Created on: 5 maj 2018
 *      Author: SF
 */

#include <fxListNC.hpp>
#include "string.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

std::array<char *, 12> choices = {
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

FxListWindowNC::FxListWindowNC(int windowWidth, int windowHeight, int windowPosX, int windowPosY):
		fxListWindowNC(newwin(windowHeight, windowWidth, windowPosY, windowPosX)),
		fxMenuNC(nullptr)
	{
	std::string title = "List";

	start_color();;
	init_pair(1, COLOR_CYAN, COLOR_BLACK);

	/* Create items */
	std::vector<ITEM *> my_items;
	for(auto &element : choices){
		my_items.push_back(new_item(element,""));
	}

	/* Crate menu */
	fxMenuNC.reset(new_menu(&my_items.front()));

	/* Create the window to be associated with the menu */
	keypad(fxListWindowNC.get(), TRUE);

	/* Set main window and sub window */
	set_menu_win(fxMenuNC.get(), fxListWindowNC.get());
	set_menu_sub(fxMenuNC.get(), derwin(fxListWindowNC.get(), windowHeight - 4, windowWidth - 2, 3, 1));
	set_menu_format(fxMenuNC.get(), windowHeight - 4, 1);

	/* Print a border around the main window and print a title */
	box(fxListWindowNC.get(), 0, 0);
	print_in_middle(fxListWindowNC.get(), 1, 0, windowWidth, (char*)title.c_str(), COLOR_PAIR(1));
	/* Print line under title */
	mvwaddch(fxListWindowNC.get(), 2, 0, ACS_LTEE);
	mvwhline(fxListWindowNC.get(), 2, 1, ACS_HLINE, 18);
	mvwaddch(fxListWindowNC.get(), 2, windowWidth - 1, ACS_RTEE);
	refresh();

	/* Post the menu */
	post_menu(fxMenuNC.get());
	wrefresh(fxListWindowNC.get());

	int c;
	while((c = wgetch(fxListWindowNC.get())) != KEY_F(1))
	{
		switch(c){
			case KEY_DOWN:
				menu_driver(fxMenuNC.get(), REQ_DOWN_ITEM);
				break;

			case KEY_UP:
				menu_driver(fxMenuNC.get(), REQ_UP_ITEM);
				break;
		}
		ITEM *cur = current_item(fxMenuNC.get());
		mvprintw(LINES - 2, 0,"%d", cur->index);
		refresh();
		wrefresh(fxListWindowNC.get());
	}

	/* Unpost and free all the memory taken up */
		unpost_menu(fxMenuNC.get());
		free_menu(fxMenuNC.get());
		for(auto &element : my_items){
			free_item(element);
		}
	endwin();

}

FxListWindowNC::~FxListWindowNC(){

}
