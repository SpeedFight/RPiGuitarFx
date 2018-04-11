/*
 * mainGtkView.hpp
 *
 *  Created on: 8 kwi 2018
 *      Author: SF
 */

#ifndef MAINGTKVIEW_HPP_
#define MAINGTKVIEW_HPP_

#include "config.hpp"
#include <gtkmm.h>

class ViewGtk{
public:
	ViewGtk(int argc, char * argv[]);
	void poolForView();

private:
	GtkWidget *buildMainWindow();

	Glib::RefPtr<Gtk::Application> app;
	std::unique_ptr<Gtk::Window> mainWindow;
};




#endif /* MAINGTKVIEW_HPP_ */
