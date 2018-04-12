/*
 * mainGtkView.cpp
 *
 *  Created on: 8 kwi 2018
 *      Author: SF
 */

#include "mainGtkView.hpp"

#define UI_FILE "glade/mainFxWindow.ui"

ViewGtk::ViewGtk(int argc, char * argv[])
//	vBox(Gtk::ORIENTATION_VERTICAL, 0),
//	fxNameLabel("Simple overdrive")

{
	app = Gtk::Application::create(argc, argv, "RPiGFX.view", Gio::APPLICATION_NON_UNIQUE);

	mainWindow.reset(new Gtk::Window());

	mainWindow->set_title("RPiGFX");
	mainWindow->set_default_size(200, 200);

	/*
	 *
	 */

	//vBox.add(fxNameLabel);
//	vBox.pack_start(fxNameLabel, Gtk::PACK_SHRINK);
//
	mainWindow->add(*buildFxWindow());

	mainWindow->show_all_children();
}



Gtk::Widget *ViewGtk::buildValueFxWindow(){
	Gtk::Box *vBoxFx = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 10));

	Gtk::Label *fxValueLabel = Gtk::manage(new Gtk::Label("Gain"));

	Glib::RefPtr<Gtk::Adjustment> m_adjustment;
	m_adjustment = Gtk::Adjustment::create(0.0, 0.0, 101.0, 0.1, 1.0, 1.0);
	Gtk::Scale *fxValueScale = Gtk::manage(new Gtk::Scale(m_adjustment));

	vBoxFx->pack_start(*fxValueLabel, Gtk::PACK_SHRINK);
	vBoxFx->pack_start(*fxValueScale, Gtk::PACK_SHRINK);

	fxValueScale->set_value(50);

	return vBoxFx;
}

Gtk::Widget *ViewGtk::buildFxWindow(){
	Gtk::Box *vBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 10));
	Gtk::Label *fxNameLabel = Gtk::manage(new Gtk::Label("Simple overdrive"));

	Gtk::Grid *gridFxValues = Gtk::manage(new Gtk::Grid());
	gridFxValues->set_row_spacing(10);
	gridFxValues->set_column_spacing(100);

	gridFxValues->attach(*buildValueFxWindow(), 0, 0, 2, 1);
	gridFxValues->attach(*buildValueFxWindow(), 1, 0, 2, 1);
	gridFxValues->attach(*buildValueFxWindow(), 2, 0, 2, 1);
	gridFxValues->attach(*buildValueFxWindow(), 0, 1, 2, 1);
	gridFxValues->attach(*buildValueFxWindow(), 1, 1, 2, 1);
	gridFxValues->attach(*buildValueFxWindow(), 2, 1, 2, 1);

	vBox->pack_start(*fxNameLabel, Gtk::PACK_SHRINK);
	vBox->pack_start(*gridFxValues, Gtk::PACK_SHRINK);

	return vBox;
}

Gtk::Widget *ViewGtk::buildMainWindow(){

}


void ViewGtk::poolForView(){
	mainWindow->show();
	app->run(*mainWindow);
}


