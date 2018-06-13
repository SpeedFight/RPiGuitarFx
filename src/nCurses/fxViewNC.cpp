/*
 * fxViewNC.cpp
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

#include "fxViewNC.hpp"
#include "string.h"

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

/*
 * FxSettingViewNC
 */

FxSettingViewNC::FxSettingViewNC(std::string newValueName, std::string newInitName, int newWindowWidth, int newWindowHeight, int newWindowPosX, int newWindowPosY):
		windowWidth(newWindowWidth  ),
		windowHeight(newWindowHeight ),
		windowPosX(newWindowPosX   ),
		windowPosY(newWindowPosY   ),
		valueName(newValueName),
		value(newInitName),
		window(newwin(newWindowHeight, newWindowWidth, newWindowPosY, newWindowPosX))
{
	box(window.get(), 0, 0);

	//print setting name
	print_in_middle(window.get(), 2, 0, windowWidth, (char*)valueName.c_str(), COLOR_PAIR(1));

	//print setting init value
	print_in_middle(window.get(), 4, 0, windowWidth, (char*)value.c_str(), COLOR_PAIR(1));

	wrefresh(window.get());
}

FxSettingViewNC::~FxSettingViewNC(){
	delwin(window.get());
	refresh();
}

void FxSettingViewNC::updateValue(std::string newValueName){
	//print setting init value
	value = newValueName;
	print_in_middle(window.get(), 4, 0, windowWidth, (char*)value.c_str(), COLOR_PAIR(1));

	wrefresh(window.get());
}

/*
 * FxInfoViewNC
 */

FxInfoViewNC::FxInfoViewNC(char *newFxname, int newColorScheme,int newWindowWidth, int newWindowHeight, int newWindowPosX, int newWindowPosY):
		windowWidth(newWindowWidth  ),
		windowHeight(newWindowHeight ),
		windowPosX(newWindowPosX   ),
		windowPosY(newWindowPosY   ),
		fxName(newFxname),
		colorScheme(newColorScheme),
		window(newwin(newWindowHeight, newWindowWidth, newWindowPosY, newWindowPosX))
{
	box(window.get(), 0, 0);

	//print setting name
	print_in_middle(window.get(), 2, 0, windowWidth, fxName, colorScheme);

	wrefresh(window.get());
}

FxInfoViewNC::~FxInfoViewNC(){
	delwin(window.get());
	refresh();
}

/*
 * FxViewNC
 */

FxViewNC::FxViewNC(){

}

FxViewNC::~FxViewNC(){

	for(auto &settingBox : settingsBoxs){
		settingBox->~FxSettingViewNC();
		}
	fxInfoBox->~FxInfoViewNC();

	refresh();
}

void FxViewNC::eraseWin(){
	for(auto &settingBox : settingsBoxs){
		if(settingBox != nullptr){
			werase(settingBox->window.get());
			redrawwin(settingBox->window.get());
			wnoutrefresh(settingBox->window.get());
		}else {
			break;
		}
	}
	doupdate();
}

void FxViewNC::refresh(){
	redrawwin(fxInfoBox->window.get());
	wnoutrefresh(fxInfoBox->window.get());


	for(auto &settingBox : settingsBoxs){
		if(settingBox != nullptr){
			redrawwin(settingBox->window.get());
			wnoutrefresh(settingBox->window.get());
		}else {
			break;
		}
	}
	doupdate();
}
