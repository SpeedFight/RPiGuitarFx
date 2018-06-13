/*
 * dialogWindowMoveFx.cpp
 *
 *  Created on: 27 kwi 2018
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

#include "dialogWindowMoveFx.hpp"

ActualFxGtkList::ActualFxGtkList(){
  //Create the Tree model:
  treeModel = Gtk::ListStore::create(columnsModel);
  set_model(treeModel);

  append_column("Current effects order", columnsModel.nameColumn);
}

ActualFxGtkList::~ActualFxGtkList(){

}

DialogWindowMoveFx::DialogWindowMoveFx(int argc, char * argv[]):
	Gtk::Window(),
	actualFxGtkList(Gtk::manage(new ActualFxGtkList()))
	{
	Glib::RefPtr<Gtk::Application> app;
	app = Gtk::Application::create(argc, argv, "moveFx.dialog", Gio::APPLICATION_NON_UNIQUE);

	set_title("move fx dialog");
	set_decorated(false);
	set_default_size(200, 400);
	set_position(Gtk::WIN_POS_CENTER);
	add(*setWidget());

	show_all();
	iconify();
}

void DialogWindowMoveFx::showDialog(){
	deiconify();
}

void DialogWindowMoveFx::hideDialog(){
	iconify();
}

Gtk::Widget *DialogWindowMoveFx::setWidget(){
	title = Gtk::manage(new Gtk::Frame("Move fx"));
	title->set_border_width(5);

	title->add(*actualFxGtkList);

	return title;
}
