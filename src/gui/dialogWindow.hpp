/*
 * dialogWindow.hpp
 *
 *  Created on: 20 kwi 2018
 *      Author: SF
 */

#ifndef DIALOGWINDOW_HPP_
#define DIALOGWINDOW_HPP_

#include "config.hpp"
#include <gtkmm.h>

class DialogWindow: Gtk::Window{
public:
	DialogWindow(int argc, char * argv[]);
	std::array<std::unique_ptr<Gtk::Button>, 4> buttons;

private:

	Gtk::Widget *setwidget();

	//build
	//buttons
	// cancel, add_next, add_prev, move, delete
};


#endif /* DIALOGWINDOW_HPP_ */
