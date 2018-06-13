/*
 * dialogWindow.hpp
 *
 *  Created on: 20 kwi 2018
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

#ifndef DIALOGWINDOWFXLIST_HPP_
#define DIALOGWINDOWFXLIST_HPP_

#include "config.hpp"
#include <gtkmm.h>

class DialogWindowFxList: Gtk::Window{
public:
	DialogWindowFxList(int argc, char * argv[]);
	std::array<std::unique_ptr<Gtk::Button>, 4> buttons;

	void showDialog();
	void hideDialog();

	void markButton(int btnToMark);

private:
	Gtk::Widget *setWidget();
	void unMarkAllButtons();

	Gtk::ButtonBox *buttonBox;
	Gtk::Frame *title;
};


#endif /* DIALOGWINDOWFXLIST_HPP_ */
