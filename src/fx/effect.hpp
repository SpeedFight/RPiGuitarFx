/*
 * effect.hpp
 *
 *  Created on: 23 mar 2018
 *      Author: SF
 */

#ifndef EFFECT_HPP_
#define EFFECT_HPP_

#include "config.hpp"
#include "controller.hpp"
#include <jackaudioio.hpp>

class Setting{
public:
	Setting(std::string newName, int *controllerValue, int initValue, int newMinValue, int newMaxValue);
	std::string *getName();
	void updatePotentiometers();
	int getValue();

private:
	std::string name;
	int *valueFromController;
	int actualValue;
	const int maxValue;
	const int minValue;

};

class IFX{
public:
	IFX(IDetector *newUserInput);
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs) {};
	virtual ~IFX() {};

	virtual const std::string *getName() = 0;
	void updateSettings();
	std::vector<Setting> *getSettings();

protected:
	IDetector *userInput;
	std::vector<Setting> settings;

};

class FXList{

public:
	FXList();
	const std::vector<std::shared_ptr<IFX>>  *getCurrentFXList();
	std::vector<std::shared_ptr<IFX>>  *getFXList();
	void updateFX();

private:
	std::vector<std::shared_ptr<IFX>> futureFX;
	std::vector<std::shared_ptr<IFX>> actualFX;
};


#endif /* EFFECT_HPP_ */
