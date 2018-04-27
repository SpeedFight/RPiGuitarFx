/*
 * dialogWindowMoveFx.cpp
 *
 *  Created on: 27 kwi 2018
 *      Author: SF
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
