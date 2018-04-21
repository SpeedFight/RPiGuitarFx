/*
 * dialogWindow.hpp
 *
 *  Created on: 20 kwi 2018
 *      Author: SF
 */

#ifndef DIALOGWINDOWFXLIST_HPP_
#define DIALOGWINDOWFXLIST_HPP_

#include "config.hpp"
#include <gtkmm.h>

class DialogWindowFxList: Gtk::Window{
public:
	DialogWindowFxList(int argc, char * argv[]);
	std::array<std::unique_ptr<Gtk::Button>, 4> buttons;

	void showDialog();
	void hideDialog();

	void markButton(int btnToMark);

private:
	Gtk::Widget *setWidget();
	void unMarkAllButtons();

	Gtk::ButtonBox *buttonBox;
	Gtk::Frame *title;
};


#endif /* DIALOGWINDOWFXLIST_HPP_ */
