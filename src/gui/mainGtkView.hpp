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

	Gtk::Widget *buildValueFxWindow();
	Gtk::Widget *buildFxWindow();
	Gtk::Widget *buildMainWindow();



	Glib::RefPtr<Gtk::Application> app;
	std::unique_ptr<Gtk::Window> mainWindow;

//	Gtk::Box vBox;
//	Gtk::Label fxNameLabel;
};




#endif /* MAINGTKVIEW_HPP_ */
