/*
 * triangleGen.hpp
 *
 *  Created on: 1 cze 2018
 *      Author: SF
 */

#ifndef TRIANGLEGEN_HPP_
#define TRIANGLEGEN_HPP_

#include "config.hpp"
#include "lfo.hpp"

class TriangleGen: public Lfo{
public:
	TriangleGen();
	void setToStart(float newFrequency, float newPhase);
	void changeFrequency(float newFrequency);
	float getSample();

	virtual ~TriangleGen();

private:
	float frequency;
	float phase;
	float diff;
	float output;
};

#endif /* TRIANGLEGEN_HPP_ */
