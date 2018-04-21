/*
 * dialogWindowAddFx.cpp
 *
 *  Created on: 21 kwi 2018
 *      Author: SF
 */

#include "dialogWindowAddFx.hpp"

AvaibleFxGtkList::AvaibleFxGtkList(){
  //Create the Tree model:
  treeModel = Gtk::ListStore::create(columnsModel);
  set_model(treeModel);

  append_column("Fx list", columnsModel.nameColumn);
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
	hide();
}

void DialogWindowAddFx::showDialog(){
	show();
}

void DialogWindowAddFx::hideDialog(){
	hide();
}

Gtk::Widget *DialogWindowAddFx::setWidget(){
	title = Gtk::manage(new Gtk::Frame("Choose FX"));
	title->set_border_width(5);

	title->add(*avaibleFxGtkList);

	return title;
}


