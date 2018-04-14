/*
 * mainGtkView.hpp
 *
 *  Created on: 8 kwi 2018
 *      Author: SF
 */

#ifndef MAINGTKVIEW_HPP_
#define MAINGTKVIEW_HPP_

#include "config.hpp"
#include "fxGtkView.hpp"
#include "fxGtkList.hpp"
#include <gtkmm.h>

class ViewGtk{
public:
	ViewGtk(int argc, char * argv[]);
	void poolForView();

private:
	Glib::RefPtr<Gtk::Application> app;
	std::unique_ptr<Gtk::Window> mainWindow;

	Gtk::Widget *mainViewWidget(FxGtkList* fxGtkList, FxGtkView *fxGtkView);
};

#endif /* MAINGTKVIEW_HPP_ */
