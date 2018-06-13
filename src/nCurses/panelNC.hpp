/*
 * panelNC.hpp
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

#ifndef PANELNC_HPP_
#define PANELNC_HPP_

#include "config.hpp"
#include <ncurses.h>
#include "panel.h"
#include "string.h"

class PanelNC{
public:
	PanelNC(WINDOW *window, int newWindowWidth, int newWindowHeight, int newWindowPosX, int newWindowPosY);
	~PanelNC();

	void hidePanel();
	void showPanel();

private:
	int windowWidth;
	int windowHeight;
	int windowPosX;
	int windowPosY;

	bool isShow;

	WINDOW* window;
	std::unique_ptr<PANEL>	panel;

};



#endif /* PANELNC_HPP_ */
