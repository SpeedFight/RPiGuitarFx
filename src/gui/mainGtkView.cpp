/*
 * mainGtkView.cpp
 *
 *  Created on: 8 kwi 2018
 *      Author: SF
 */

#include "mainGtkView.hpp"

#define UI_FILE "glade/mainFxWindow.ui"

ViewGtk::ViewGtk(int argc, char * argv[]){
	app = Gtk::Application::create(argc, argv, "RPiGFX.view", Gio::APPLICATION_NON_UNIQUE);

	mainWindow.reset(new Gtk::Window());

	mainWindow->set_title("RPiGFX");
	mainWindow->set_default_size(800, 600);

//	FxGtkView *fxBox = Gtk::manage(new FxGtkView("simple fx"));
//	mainWindow->add(*fxBox);
	mainWindow->add(*mainViewWidget());

	//mainWindow->set_decorated(false);

	mainWindow->show_all_children();
}

Gtk::Widget *ViewGtk::mainViewWidget(){
	Gtk::Box *mainWindowBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 10));
	Gtk::Grid *lowePartMainWindowBox = Gtk::manage(new Gtk::Grid());
	Gtk::Label *title = Gtk::manage(new Gtk::Label("RPiGuitarFx"));
	Gtk::Label *dummyList = Gtk::manage(new Gtk::Label("FxList"));

	lowePartMainWindowBox->set_row_spacing(100);
	lowePartMainWindowBox->set_column_spacing(100);

	mainWindowBox->pack_start(*title, Gtk::PACK_SHRINK);
	mainWindowBox->pack_start(*lowePartMainWindowBox, Gtk::PACK_EXPAND_WIDGET);

	FxGtkView *fxBox = Gtk::manage(new FxGtkView("simple fx"));

	lowePartMainWindowBox->attach(*dummyList, 	0, 0, 2, 5);
	lowePartMainWindowBox->attach(*fxBox, 		3, 0, 6, 5);


	return mainWindowBox;
}

void ViewGtk::poolForView(){
	mainWindow->show();
	app->run(*mainWindow);
}


