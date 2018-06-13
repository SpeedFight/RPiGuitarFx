/*
 * fxListNc.hpp
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

#ifndef LISTNC_HPP_
#define LISTNC_HPP_

#include "config.hpp"
#include <ncurses.h>
#include <panel.h>
#include <menu.h>

class ListWindowNC{
public:
	ListWindowNC(std::vector<char *> newElements, std::string title, int windowWidth, int windowHeight, int windowPosX, int windowPosY);
	~ListWindowNC();

	void selectFirstIndex();
	void selectIndex(unsigned int newIndex);
	void selectByDiff(int diff);
	void setNewList(std::vector<char *> newElements);
	void clearList();
	int getSelectedIndex();
	void refreshWindow();

	std::unique_ptr<WINDOW> fxListWindowNC;
	std::unique_ptr<MENU> fxMenuNC;

private:
	int windowWidth;
	int windowHeight;
	int windowPosX;
	int windowPosY;

	std::vector<ITEM *> listOfElements;

	std::vector<std::string> namesOfElements;

//	void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);

};



#endif /* LISTNC_HPP_ */
