/*
 * fxGtkView.cpp
 *
 *  Created on: 12 kwi 2018
 *      Author: SF
 */

#include "fxGtkView.hpp"

FxGtkView::FxGtkView():
	Gtk::Box(Gtk::ORIENTATION_VERTICAL, 10)
{
	Gtk::Frame *fxNameFrame = Gtk::manage(new Gtk::Frame());
	Gtk::Label *fxNameLabel = Gtk::manage(new Gtk::Label("Simple overdrive"));

	Gtk::Grid *gridFxValues = Gtk::manage(new Gtk::Grid());
	gridFxValues->set_row_spacing(10);
	gridFxValues->set_column_spacing(100);

	FxSetting *set1 = Gtk::manage(new FxSetting());
	gridFxValues->attach(*set1, 0, 0, 2, 1);
	gridFxValues->attach(*buildValueFxWidget(), 1, 0, 2, 1);
	gridFxValues->attach(*buildValueFxWidget(), 2, 0, 2, 1);
	gridFxValues->attach(*buildValueFxWidget(), 0, 1, 2, 1);
	gridFxValues->attach(*buildValueFxWidget(), 1, 1, 2, 1);
	gridFxValues->attach(*buildValueFxWidget(), 2, 1, 2, 1);

	//fxNameFrame->set_shadow_type(Gtk::SHADOW_IN);
	//fxNameFrame->override_background_color(Gdk::RGBA("green"));
	fxNameFrame->add(*fxNameLabel);
	pack_start(*fxNameFrame, Gtk::PACK_SHRINK);
	pack_start(*gridFxValues, Gtk::PACK_SHRINK);
}

Gtk::Widget *FxGtkView::buildValueFxWidget(){
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

FxGtkView::~FxGtkView() {}

/*
 * FxSetting
 */

FxGtkView::FxSetting::FxSetting():
	Gtk::Box(Gtk::ORIENTATION_VERTICAL, 10),
	adjustment(Gtk::Adjustment::create(0.0, 0.0, 101.0, 0.1, 1.0, 1.0)),
	fxValueLabel(Gtk::manage(new Gtk::Label("Gain"))),
	fxValueScale(Gtk::manage(new Gtk::Scale(adjustment)))
{
	pack_start(*fxValueLabel, Gtk::PACK_SHRINK);
	pack_start(*fxValueScale, Gtk::PACK_SHRINK);

	fxValueScale->set_value(50);
}

FxGtkView::FxSetting::~FxSetting() {}
