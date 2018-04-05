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
	Setting(std::string newName, int *controllerValue, int initValue, int newMaxValue, int newMinValue );
	std::string *getName();
	void update();
	int getValue();

private:
	std::string name;
	int *valueFromController;
	int value;
	const int maxValue;
	const int minValue;

};

class IFX{
public:
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs) {};
	virtual ~IFX() {};

	virtual const std::string *getName() {};
	virtual void setSettings(int *settings) {};
	virtual std::vector<Setting> *getSettings() {};
protected:
	std::vector<Setting> settings(8);

};

class FXList{

public:
	//FXList();
	const std::list<std::shared_ptr<IFX>>  *getCurrentFXList();
	std::list<std::shared_ptr<IFX>>  *getFXList();
	void updateFX();

private:
	std::list<std::shared_ptr<IFX>> futureFX;
	std::list<std::shared_ptr<IFX>> actualFX;
};


#endif /* EFFECT_HPP_ */
