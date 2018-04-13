/*
 * fxGtkView.hpp
 *
 *  Created on: 12 kwi 2018
 *      Author: SF
 */

#ifndef FXGTKVIEW_HPP_
#define FXGTKVIEW_HPP_

#include "config.hpp"
#include <gtkmm.h>

class FxGtkView: public Gtk::Box{
public:
	FxGtkView(std::string fxName);
	void changeView();
	virtual ~FxGtkView();

	Gtk::Grid *gridFxValues;
	Gtk::Frame *fxNameFrame;
	Gtk::Label *fxNameLabel;

protected:

	class FxSetting: public Gtk::Box{
	public:
		FxSetting(std::string valueName, double initVal, double min, double max, double stepIncrement);
		virtual ~FxSetting();

		Gtk::Label *fxValueLabel;
		Gtk::Scale *fxValueScale;
	};

	std::vector<FxSetting> fxValues;
};

#endif /* FXGTKVIEW_HPP_ */
