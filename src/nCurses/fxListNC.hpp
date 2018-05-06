/*
 * fxListNc.hpp
 *
 *  Created on: 5 maj 2018
 *      Author: SF
 */

#ifndef FXLISTNC_HPP_
#define FXLISTNC_HPP_

#include "config.hpp"
#include <ncurses.h>
#include <panel.h>
#include <menu.h>

class FxListWindowNC{
public:
	FxListWindowNC(int windowWidth, int windowHeight, int windowPosX, int windowPosY);
	~FxListWindowNC();

	void selectFirstIndex();
	void selectIndex(unsigned int newIndex);
	void selectByDiff(int diff);
	void setNewListsElements(std::vector<std::string> newElements);
	int getSelectedIndex();
	void refreshWindow();

private:
	std::unique_ptr<WINDOW> fxListWindowNC;
	std::unique_ptr<MENU> fxMenuNC;

	std::vector<std::string> namesOfElements;

};



#endif /* FXLISTNC_HPP_ */
