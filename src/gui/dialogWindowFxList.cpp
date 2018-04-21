/*
 * dialogWindow.cpp
 *
 *  Created on: 20 kwi 2018
 *      Author: SF
 */

#include <dialogWindowFxList.hpp>

DialogWindowFxList::DialogWindowFxList(int argc, char * argv[]):
	Gtk::Window(),
	buttonBox(Gtk::manage(new Gtk::ButtonBox(Gtk::ORIENTATION_HORIZONTAL)))
	{
	Glib::RefPtr<Gtk::Application> app;
	app = Gtk::Application::create(argc, argv, "edit.dialog", Gio::APPLICATION_NON_UNIQUE);

	set_title("Dialog window");
	set_decorated(false);
	set_default_size(300, 100);
	set_position(Gtk::WIN_POS_CENTER);
	add(*setWidget());

	show_all();
	iconify();
}

Gtk::Widget *DialogWindowFxList::setWidget(){
	buttons[DialogWindowBtn::cancelBtn].reset(Gtk::manage(new Gtk::Button("Cancel")));
	buttons[DialogWindowBtn::addNextBtn].reset(Gtk::manage(new Gtk::Button("Add FX")));
	buttons[DialogWindowBtn::movelBtn].reset(Gtk::manage(new Gtk::Button("Move")));
	buttons[DialogWindowBtn::deletelBtn].reset(Gtk::manage(new Gtk::Button("Delete")));

	buttonBox->set_layout(Gtk::BUTTONBOX_SPREAD);
	buttonBox->set_spacing(10);
	buttonBox->set_border_width(5);

	buttonBox->pack_start(*buttons[DialogWindowBtn::cancelBtn].get(), Gtk::PACK_EXPAND_WIDGET);
	buttonBox->pack_start(*buttons[DialogWindowBtn::addNextBtn].get(), Gtk::PACK_EXPAND_WIDGET);
	buttonBox->pack_start(*buttons[DialogWindowBtn::movelBtn].get(), Gtk::PACK_EXPAND_WIDGET);
	buttonBox->pack_start(*buttons[DialogWindowBtn::deletelBtn].get(), Gtk::PACK_EXPAND_WIDGET);

	title = Gtk::manage(new Gtk::Frame("Choose action"));
	title->set_border_width(5);

	title->add(*buttonBox);

	return title;
}

void DialogWindowFxList::unMarkAllButtons(){
	for(auto &button : buttons){
		button.get()->override_background_color(Gdk::RGBA(fxDialogListColor::unselectedButtonCollor));
	}
}

void DialogWindowFxList::showDialog(){
	deiconify();
}

void DialogWindowFxList::hideDialog(){
	iconify();
	unMarkAllButtons();
}

void DialogWindowFxList::markButton(int btnToMark){
	unMarkAllButtons();

	if(btnToMark < 0){
		btnToMark = 0;
	}else if (btnToMark > buttons.size() - 1){
		btnToMark = buttons.size() - 1;
	}

	buttons[btnToMark].get()->override_background_color(Gdk::RGBA(fxDialogListColor::selectedButtonCollor));
}




