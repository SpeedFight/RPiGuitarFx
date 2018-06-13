/*
 * panelNC.cpp
 *
 *  Created on: 7 maj 2018
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

#include "panelNC.hpp"


PanelNC::PanelNC(WINDOW *newWindow, int newWindowWidth, int newWindowHeight, int newWindowPosX, int newWindowPosY):
		windowWidth(newWindowWidth  ),
		windowHeight(newWindowHeight ),
		windowPosX(newWindowPosX   ),
		windowPosY(newWindowPosY   ),
		isShow(false)
			{

	window = newWindow;
	panel.reset(new_panel(window)); 	/* Push 0, order: stdscr-0 */
	update_panels();

	hide_panel(panel.get());
	doupdate();

//	int ch;
//	while((ch = getch()) != KEY_F(1))
//	{	switch(ch)
//		{	case 'a':
//				if(isShow)
//				{	hide_panel(panel.get());
//					isShow = false;
//				}
//				else
//				{	show_panel(panel.get());
//					isShow = true;
//				}
//				break;
//		}
//		update_panels();
//		doupdate();
//	}

}

PanelNC::~PanelNC(){

}

void PanelNC::hidePanel(){
	if(isShow){
		hide_panel(panel.get());
		isShow = false;
		update_panels();
		doupdate();
	}
}

void PanelNC::showPanel(){
	if(!isShow){
		show_panel(panel.get());
		isShow = true;
		update_panels();
		doupdate();
	}
}
