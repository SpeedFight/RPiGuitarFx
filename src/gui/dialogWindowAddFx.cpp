/*
 * dialogWindowAddFx.cpp
 *
 *  Created on: 21 kwi 2018
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

#include "dialogWindowAddFx.hpp"

AvaibleFxGtkList::AvaibleFxGtkList(){
  //Create the Tree model:
  treeModel = Gtk::ListStore::create(columnsModel);
  set_model(treeModel);

  append_column("Avaible effects", columnsModel.nameColumn);
}

AvaibleFxGtkList::~AvaibleFxGtkList(){

}

DialogWindowAddFx::DialogWindowAddFx(int argc, char * argv[]):
	Gtk::Window(),
	avaibleFxGtkList(Gtk::manage(new AvaibleFxGtkList()))
	{
	Glib::RefPtr<Gtk::Application> app;
	app = Gtk::Application::create(argc, argv, "addFx.dialog", Gio::APPLICATION_NON_UNIQUE);

	set_title("Dialog window");
	set_decorated(false);
	set_default_size(200, 400);
	set_position(Gtk::WIN_POS_CENTER);
	add(*setWidget());

	show_all();
	iconify();
}

void DialogWindowAddFx::showDialog(){
	deiconify();
}

void DialogWindowAddFx::hideDialog(){
	iconify();
}

Gtk::Widget *DialogWindowAddFx::setWidget(){
	title = Gtk::manage(new Gtk::Frame("Choose FX"));
	title->set_border_width(5);

	title->add(*avaibleFxGtkList);

	return title;
}


