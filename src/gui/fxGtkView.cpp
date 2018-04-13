/*
 * fxGtkView.cpp
 *
 *  Created on: 12 kwi 2018
 *      Author: SF
 */

#include "fxGtkView.hpp"

FxGtkView::FxGtkView(std::string fxName):
	Gtk::Box(Gtk::ORIENTATION_VERTICAL, 10),
	gridFxValues(Gtk::manage(new Gtk::Grid())),
	fxNameFrame(Gtk::manage(new Gtk::Frame())),
	fxNameLabel(Gtk::manage(new Gtk::Label(fxName)))
{
	gridFxValues->set_row_spacing(10);
	gridFxValues->set_column_spacing(100);

	//fxNameFrame->set_shadow_type(Gtk::SHADOW_IN);
	//fxNameFrame->override_background_color(Gdk::RGBA("green"));

	fxNameFrame->add(*fxNameLabel);
	pack_start(*fxNameFrame, Gtk::PACK_SHRINK);
	pack_start(*gridFxValues, Gtk::PACK_SHRINK);

	/*
	 * fill setting grid
	 */

	FxSetting *set1, *set2, *set3, *set4, *set5, *set6;
	set1 = Gtk::manage(new FxSetting("gain", 0.0, 0.0, 100.0, 0.1));
	set2 = Gtk::manage(new FxSetting("gain", 0.0, 0.0, 100.0, 0.1));
	set3 = Gtk::manage(new FxSetting("gain", 0.0, 0.0, 100.0, 0.1));
	set4 = Gtk::manage(new FxSetting("gain", 0.0, 0.0, 100.0, 0.1));
	set5 = Gtk::manage(new FxSetting("gain", 0.0, 0.0, 100.0, 0.1));
	set6 = Gtk::manage(new FxSetting("gain", 0.0, 0.0, 100.0, 0.1));

	gridFxValues->attach(*set1, 0, 0, 2, 1);
	gridFxValues->attach(*set2, 1, 0, 2, 1);
	gridFxValues->attach(*set3, 2, 0, 2, 1);
	gridFxValues->attach(*set4, 0, 1, 2, 1);
	gridFxValues->attach(*set5, 1, 1, 2, 1);
	gridFxValues->attach(*set6, 2, 1, 2, 1);
}

FxGtkView::~FxGtkView() {}

/*
 * FxSetting
 */

FxGtkView::FxSetting::FxSetting(std::string valueName, double initVal, double min, double max, double stepIncrement):
	Gtk::Box(Gtk::ORIENTATION_VERTICAL, 10),
	fxValueLabel(Gtk::manage(new Gtk::Label(valueName))),
	fxValueScale(Gtk::manage(new Gtk::Scale(Gtk::Adjustment::create(initVal, min, max, stepIncrement, 10, 0))))
{
	pack_start(*fxValueLabel, Gtk::PACK_SHRINK);
	pack_start(*fxValueScale, Gtk::PACK_SHRINK);
}

FxGtkView::FxSetting::~FxSetting() {}
