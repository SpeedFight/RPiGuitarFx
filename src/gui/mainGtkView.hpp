/*
 * mainGtkView.hpp
 *
 *  Created on: 8 kwi 2018
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

#ifndef MAINGTKVIEW_HPP_
#define MAINGTKVIEW_HPP_

#include "config.hpp"
#include "fxGtkView.hpp"
#include "fxGtkList.hpp"
#include <gtkmm.h>

class ViewGtk{
public:
	ViewGtk(int argc, char * argv[]);
	void poolForView();
	FxGtkView *getFxGtkView();
	FxGtkList *getFxGtkList();
private:
	Glib::RefPtr<Gtk::Application> app;
	std::unique_ptr<Gtk::Window> mainWindow;

	FxGtkView *fxBox;
	FxGtkList *fxlist;

	Gtk::Box *mainWindowBox;
	Gtk::Box *fxViewBox;
	Gtk::Grid *lowePartMainWindowBox;
	Gtk::Label *title;
	Gtk::ScrolledWindow *scrollForFxList;

	Gtk::Widget *mainViewWidget(FxGtkList* fxGtkList, FxGtkView *fxGtkView);
};

#endif /* MAINGTKVIEW_HPP_ */
