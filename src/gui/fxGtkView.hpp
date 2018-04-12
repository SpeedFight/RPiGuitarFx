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

	/*
	 * TODO
	 *  1) funkcje do ustawiania wyswietlanych wartosci dla efektow
	 *  	- zmiany nazw
	 *  	- zmiany wartosci
	 *  	- dynamiczna ilosc potencjometrow
	 */

class FxGtkView: public Gtk::Box{
public:
	FxGtkView();
	void changeView();
	virtual ~FxGtkView();

private:
	std::string fxName;
	std::vector<std::string> fxValuesNames;
	std::vector<double> fxValues;

	Gtk::Widget *buildValueFxWidget();
};

#endif /* FXGTKVIEW_HPP_ */
