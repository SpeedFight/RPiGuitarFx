/*
 * fxViewNC.hpp
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

#ifndef FXVIEWNC_HPP_
#define FXVIEWNC_HPP_


#include "config.hpp"
#include "panelNC.hpp"

#include <ncurses.h>

class FxSettingViewNC{
public:
	FxSettingViewNC(std::string newValueName, std::string newValue, int newWindowWidth, int newWindowHeight, int newWindowPosX, int newWindowPosY);
	~FxSettingViewNC();

	void updateValue(std::string newValueName);

	std::unique_ptr<WINDOW> window;

private:
	int windowWidth;
	int windowHeight;
	int windowPosX;
	int windowPosY;

	std::string valueName;
	std::string value;
};

class FxInfoViewNC{
public:
	FxInfoViewNC(char *newFxname, int newColorScheme,int newWindowWidth, int newWindowHeight, int newWindowPosX, int newWindowPosY);
	~FxInfoViewNC();

	std::unique_ptr<WINDOW> window;

private:
	int windowWidth;
	int windowHeight;
	int windowPosX;
	int windowPosY;

	char *fxName;
	int colorScheme;
};



class FxViewNC{
public:

	FxViewNC();
	~FxViewNC();

	void refresh();
	void eraseWin();

	std::array<std::unique_ptr<FxSettingViewNC>, 7> settingsBoxs;
	std::unique_ptr<FxInfoViewNC> fxInfoBox;

private:

};




#endif /* FXVIEWNC_HPP_ */
