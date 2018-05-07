/*
 * fxListNc.hpp
 *
 *  Created on: 5 maj 2018
 *      Author: SF
 */

#ifndef LISTNC_HPP_
#define LISTNC_HPP_

#include "config.hpp"
#include <ncurses.h>
#include <panel.h>
#include <menu.h>

class ListWindowNC{
public:
	ListWindowNC(int windowWidth, int windowHeight, int windowPosX, int windowPosY);
	~ListWindowNC();

	void selectFirstIndex();
	void selectIndex(unsigned int newIndex);
	void selectByDiff(int diff);
	void setNewList(std::vector<char *> newElements);
	void clearList();
	int getSelectedIndex();
	void refreshWindow();

private:
	int windowWidth;
	int windowHeight;
	int windowPosX;
	int windowPosY;
	std::unique_ptr<WINDOW> fxListWindowNC;
	std::unique_ptr<MENU> fxMenuNC;
	std::vector<ITEM *> listOfElements;

	std::vector<std::string> namesOfElements;

	void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);

};



#endif /* LISTNC_HPP_ */
