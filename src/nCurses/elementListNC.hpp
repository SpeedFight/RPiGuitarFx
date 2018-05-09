/*
 * elementNC.hpp
 *
 *  Created on: 9 maj 2018
 *      Author: SF
 */

#ifndef ELEMENTLISTNC_HPP_
#define ELEMENTLISTNC_HPP_

#include "config.hpp"

#include <ncurses.h>
#include "listNC.hpp"
#include "panelNC.hpp"

class ElementListNC{
public:

	ElementListNC(std::vector<char *> newElements, std::string title, int newWindowWidth, int newWindowHeight, int newWindowPosX, int newWindowPosY);

	std::unique_ptr<ListWindowNC> listWindow;
	std::unique_ptr<PanelNC> panel;

private:

};



#endif /* ELEMENTLISTNC_HPP_ */
