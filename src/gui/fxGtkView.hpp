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


class FxGtkView: public Gtk::Widget{
public:
	FxGtkView();
	void changeView();

private:

};



#endif /* FXGTKVIEW_HPP_ */
