/*
 * dialogWindow.cpp
 *
 *  Created on: 20 kwi 2018
 *      Author: SF
 */

#include "dialogWindow.hpp"
#include <stddef.h>

DialogWindow::DialogWindow(int argc, char * argv[]):
	Gtk::Window()
	{

	Glib::RefPtr<Gtk::Application> app;
	app = Gtk::Application::create(argc, argv, "EditDialog", Gio::APPLICATION_NON_UNIQUE);

	//app.hold();

	set_title("Dialog window");
	set_decorated(false);
	set_default_size(400, 200);
	set_position(Gtk::WIN_POS_CENTER);
//	show();
	//show_all();
}

Gtk::Widget *DialogWindow::setwidget(){
	buttons[DialogWindowBtn::cancelBtn].reset(Gtk::manage(new Gtk::Button("Cancel")));
	buttons[DialogWindowBtn::addNextBtn].reset(Gtk::manage(new Gtk::Button("Add FX")));
	buttons[DialogWindowBtn::movelBtn].reset(Gtk::manage(new Gtk::Button("Move")));
	buttons[DialogWindowBtn::deletelBtn].reset(Gtk::manage(new Gtk::Button("Delete")));

}




