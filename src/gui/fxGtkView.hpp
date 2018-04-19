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
	FxGtkView();
	void changeView();
	virtual ~FxGtkView();

	Gtk::Grid *gridFxValues;
	Gtk::Frame *fxNameFrame;
	Gtk::Label *fxNameLabel;

	class FxSetting: public Gtk::Box{
	public:
		FxSetting(std::string valueName, double initVal, double min, double max, double stepIncrement);
		virtual ~FxSetting();
		void setFxSetting(std::string valueName, double initVal, double min, double max, double stepIncrement);

		Gtk::Label *fxValueLabel;
		Gtk::Scale *fxValueScale;
		};

	std::array<std::unique_ptr<FxSetting>, 5> fxSettings;
//	FxSetting *set1, *set2, *set3, *set4, *set5, *set6;
	std::vector<FxSetting> fxValues;
};


#endif /* FXGTKVIEW_HPP_ */
