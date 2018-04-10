/*
 * mainGtkView.cpp
 *
 *  Created on: 8 kwi 2018
 *      Author: SF
 */

#include "mainGtkView.hpp"

#define UI_FILE "glade/mainFxWindow.ui"

ViewGtk::ViewGtk(int argc, char * argv[]){
	  auto app = Gtk::Application::create(argc, argv, "org.gtkmm", Gio::APPLICATION_NON_UNIQUE);

	  Gtk::Window window;

	  window.set_title("gtkmm");
	  window.set_default_size(200, 200);

	  app->run(window);
}

GtkWidget *ViewGtk::buildMainWindow(){

}


