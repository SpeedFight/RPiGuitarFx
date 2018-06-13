/*
 * mainGtkView.cpp
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

#include "mainGtkView.hpp"

#define UI_FILE "glade/mainFxWindow.ui"

ViewGtk::ViewGtk(int argc, char * argv[]){
	app = Gtk::Application::create(argc, argv, "RPiGFX.view", Gio::APPLICATION_NON_UNIQUE);

	mainWindow.reset(new Gtk::Window());

	mainWindow->set_title("RPiGFX");
	mainWindow->set_default_size(592, 448);

#ifdef __arm__
	mainWindow->set_decorated(false);
	mainWindow->fullscreen();
#endif

	fxBox = Gtk::manage(new FxGtkView());
	fxlist = Gtk::manage(new FxGtkList());

	mainWindow->add(*mainViewWidget(fxlist, fxBox));

	mainWindow->show_all_children();
}

Gtk::Widget *ViewGtk::mainViewWidget(FxGtkList* fxGtkList, FxGtkView *fxGtkView){
	mainWindowBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 10));
	lowePartMainWindowBox = Gtk::manage(new Gtk::Grid());
	title = Gtk::manage(new Gtk::Label("RPiGuitarFx"));
	scrollForFxList = Gtk::manage(new Gtk::ScrolledWindow());
	fxViewBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 10));

	lowePartMainWindowBox->set_row_spacing(45);
	lowePartMainWindowBox->set_column_spacing(30);

	mainWindowBox->pack_start(*title, Gtk::PACK_EXPAND_WIDGET);
	mainWindowBox->pack_start(*lowePartMainWindowBox, Gtk::PACK_EXPAND_WIDGET);

	scrollForFxList->add(*fxGtkList);
	scrollForFxList->set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_ALWAYS);

	fxViewBox->pack_start(*fxGtkView, Gtk::PACK_EXPAND_WIDGET);

	lowePartMainWindowBox->attach(*scrollForFxList, 	0, 0, 1, 9);
	lowePartMainWindowBox->attach(*fxViewBox, 			1, 0, 7, 9);

	return mainWindowBox;
}

void ViewGtk::poolForView(){
	mainWindow->show();
	app->run(*mainWindow);
}

FxGtkView *ViewGtk::getFxGtkView(){
	return fxBox;
}

FxGtkList *ViewGtk::getFxGtkList(){
	return fxlist;
}


