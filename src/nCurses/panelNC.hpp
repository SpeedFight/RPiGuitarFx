/*
 * panelNC.hpp
 *
 *  Created on: 7 maj 2018
 *      Author: SF
 */

#ifndef PANELNC_HPP_
#define PANELNC_HPP_

#include "config.hpp"
#include <ncurses.h>
#include "panel.h"
#include "string.h"

class PanelNC{
public:
	PanelNC(int newWindowWidth, int newWindowHeight, int newWindowPosX, int newWindowPosY);
	~PanelNC();


private:
	int windowWidth;
	int windowHeight;
	int windowPosX;
	int windowPosY;

	std::unique_ptr<WINDOW> window;
	std::unique_ptr<PANEL>	panel;

	void init_wins(WINDOW **wins, int n);
	void win_show(WINDOW *win, char *label, int label_color);
	void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);

};



#endif /* PANELNC_HPP_ */
