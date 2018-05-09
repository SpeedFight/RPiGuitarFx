/*
 * elementNC.cpp
 *
 *  Created on: 9 maj 2018
 *      Author: SF
 */

#include <elementListNC.hpp>

ElementListNC::ElementListNC(std::vector<char *> newElements, std::string title, int newWindowWidth, int newWindowHeight, int newWindowPosX, int newWindowPosY):
	listWindow(new ListWindowNC(newElements, title, newWindowWidth, newWindowHeight, newWindowPosX, newWindowPosY)),
	panel(new PanelNC(listWindow->fxListWindowNC.get(), newWindowWidth, newWindowHeight, newWindowPosX, newWindowPosY))
{

}



