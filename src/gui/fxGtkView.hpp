/*
 * fxGtkView.hpp
 *
 *  Created on: 12 kwi 2018
 *      Author: SF
 */

/*
RPiGuitarFx
Copyright (C) 2018  SpeedFight

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
