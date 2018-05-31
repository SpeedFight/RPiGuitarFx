/*
 * toneStackEq.hpp
 *
 *  Created on: 2 maj 2018
 *      Author: SF
 */

#ifndef TONESTACKEQ_HPP_
#define TONESTACKEQ_HPP_

#include "effect.hpp"

class ToneStackEq: public IFX{
public:
	virtual void process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs);
	ToneStackEq(IDetector *newUserInput);
	~ToneStackEq();

	const std::string *getName();
	std::vector<Setting> *getSettings();

private:
	void calculateNewCoef(float b, float m, float t);

	 static const std::string nameFx;
	 float C1, C2, C3, R1, R2, R3, R4;
//	 float fs;
	 float c;

		struct {
				double a1, a2, a3;
				double b1, b2, b3;
		} acoef; // analog coefficients

	std::array<float,4> numCoeff = {0, 0, 0, 0};
	std::array<float,4> denomCoeff = {0, 0, 0, 0};
};



#endif /* TONESTACKEQ_HPP_ */
