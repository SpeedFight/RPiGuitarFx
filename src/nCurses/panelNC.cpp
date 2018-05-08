/*
 * panelNC.cpp
 *
 *  Created on: 7 maj 2018
 *      Author: SF
 */
#include "panelNC.hpp"

#include "listNC.hpp"

typedef struct _PANEL_DATA {
	int hide;	/* TRUE if panel is hidden */
}PANEL_DATA;

#define NLINES 10
#define NCOLS 40

void PanelNC::print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color){
	int length, x, y;
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

/* Show the window with a border and a label */
void PanelNC::win_show(WINDOW *win, char *label, int label_color){
	int startx, starty, height, width;

	getbegyx(win, starty, startx);
	getmaxyx(win, height, width);

	box(win, 0, 0);
	mvwaddch(win, 2, 0, ACS_LTEE);
	mvwhline(win, 2, 1, ACS_HLINE, width - 2);
	mvwaddch(win, 2, width - 1, ACS_RTEE);

//	print_in_middle(win, 1, 0, width, label, COLOR_PAIR(label_color));
}

/* Put all the windows */
void PanelNC::init_wins(WINDOW **wins, int n){
	int x, y, i;
	char label[80];

	y = 2;
	x = 10;
	for(i = 0; i < n; ++i)
	{	wins[i] = newwin(NLINES, NCOLS, y, x);
		sprintf(label, "Window Number %d", i + 1);
		win_show(wins[i], label, i + 1);
		y += 3;
		x += 7;
	}
}

PanelNC::PanelNC(WINDOW *window, int newWindowWidth, int newWindowHeight, int newWindowPosX, int newWindowPosY):
		windowWidth(newWindowWidth  ),
		windowHeight(newWindowHeight ),
		windowPosX(newWindowPosX   ),
		windowPosY(newWindowPosY   )
			{
	WINDOW *my_wins[3];
	PANEL  *my_panels[3];
	PANEL_DATA panel_datas[3];
	PANEL_DATA *temp;
	int ch;

	/* Initialize all the colors */
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);

//	init_wins(my_wins, 3);

	my_wins[0] = window;

	/* Attach a panel to each window */ 	/* Order is bottom up */
	my_panels[0] = new_panel(my_wins[0]); 	/* Push 0, order: stdscr-0 */
	/* Initialize panel datas saying that nothing is hidden */
	panel_datas[0].hide = FALSE;

	set_panel_userptr(my_panels[0], &panel_datas[0]);

	/* Update the stacking order. 2nd panel will be on top */
	update_panels();

	/* Show it on the screen */
//	attron(COLOR_PAIR(4));
//	mvprintw(LINES - 3, 0, "Show or Hide a window with 'a'(first window)  'b'(Second Window)  'c'(Third Window)");
//	mvprintw(LINES - 2, 0, "F1 to Exit");
//
//	attroff(COLOR_PAIR(4));
	doupdate();

	while((ch = getch()) != KEY_F(1))
	{	switch(ch)
		{	case 'a':
				temp = (PANEL_DATA *)panel_userptr(my_panels[0]);
				if(temp->hide == FALSE)
				{	hide_panel(my_panels[0]);
					temp->hide = TRUE;
				}
				else
				{	show_panel(my_panels[0]);
					temp->hide = FALSE;
				}
				break;
		}
		update_panels();
		doupdate();
	}

}

PanelNC::~PanelNC(){

}

void PanelNC::hidePanel(){
	hide_panel(my_panels[0]);
}

void PanelNC::showPanel(){
	show_panel(my_panels[0]);
}
