/*
 * mainGtkView.hpp
 *
 *  Created on: 8 kwi 2018
 *      Author: SF
 */

#ifndef MAINGTKVIEW_HPP_
#define MAINGTKVIEW_HPP_

#include "config.hpp"

class ViewGtk{
public:
	ViewGtk(int argc, char * argv[]);

private:
	GtkWidget *buildMainWindow();
};




#endif /* MAINGTKVIEW_HPP_ */
