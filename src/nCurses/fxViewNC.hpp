/*
 * fxViewNC.hpp
 *
 *  Created on: 5 maj 2018
 *      Author: SF
 */

#ifndef FXVIEWNC_HPP_
#define FXVIEWNC_HPP_


#include "config.hpp"
#include "panelNC.hpp"

#include <ncurses.h>

class FxSettingViewNC{
public:
	FxSettingViewNC(std::string newValueName, std::string newValue, int newWindowWidth, int newWindowHeight, int newWindowPosX, int newWindowPosY);
	~FxSettingViewNC();

	void updateValue(std::string newValueName);

	std::unique_ptr<WINDOW> window;

private:
	int windowWidth;
	int windowHeight;
	int windowPosX;
	int windowPosY;

	std::string valueName;
	std::string value;
};

class FxInfoViewNC{
public:
	FxInfoViewNC(std::string newFxname, int newColorScheme,int newWindowWidth, int newWindowHeight, int newWindowPosX, int newWindowPosY);
	~FxInfoViewNC();

	std::unique_ptr<WINDOW> window;

private:
	int windowWidth;
	int windowHeight;
	int windowPosX;
	int windowPosY;

	std::string fxName;
	int colorScheme;
};



class FxViewNC{
public:

	std::array<std::unique_ptr<FxSettingViewNC>, 7> settingsBoxs;
	std::unique_ptr<FxInfoViewNC> fxInfoBox;

private:

};




#endif /* FXVIEWNC_HPP_ */
