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
	mainWindow->set_default_size(200, 200);
}

GtkWidget *ViewGtk::buildMainWindow(){

}

void ViewGtk::poolForView(){
	mainWindow->show();
	app->run(*mainWindow);
}


