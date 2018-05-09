/*
 * elementNC.hpp
 *
 *  Created on: 9 maj 2018
 *      Author: SF
 */

#ifndef ELEMENTNC_HPP_
#define ELEMENTNC_HPP_

#include "config.hpp"

#include <ncurses.h>
#include "listNC.hpp"
#include "panelNC.hpp"

class ElementNC{
public:

	ElementNC(std::vector<char *> newElements, std::string title, int newWindowWidth, int newWindowHeight, int newWindowPosX, int newWindowPosY);

	std::unique_ptr<ListWindowNC> listWindow;
	std::unique_ptr<PanelNC> panel;

private:

};



#endif /* ELEMENTNC_HPP_ */
