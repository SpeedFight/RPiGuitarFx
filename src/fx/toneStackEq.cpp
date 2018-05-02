/*
 * toneStackEq.cpp
 *
 *  Created on: 2 maj 2018
 *      Author: SF
 */

#include "toneStackEq.hpp"

const std::string ToneStackEq::nameFx("Tone stack EQ");

void ToneStackEq::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){

	static float c = 2*fs;
	static std::array<float,6> prevIn = {0 , 0, 0, 0, 0, 0};
	static float lowPot, midPot, highPot;
	float B0, B1, B2, B3, A0, A1, A2, A3;

	//pot give value from 0 to 100;
	float tmpLowPot = settings.at(ControllerInput::pot2).getValue()  / 100.0;
	float tmpMidPot = settings.at(ControllerInput::pot3).getValue()  / 100.0;
	float tmpHighPot = settings.at(ControllerInput::pot4).getValue() / 100.0;

	if(lowPot != tmpLowPot || midPot != tmpMidPot || highPot != tmpHighPot){
		lowPot 	= tmpLowPot;
		midPot 	= tmpMidPot;
		highPot = tmpHighPot;

		//calculate coeffecients
		float b1 = highPot * C1 * highR + midPot * C3 * midR + lowPot * (C1 * lowR + C2 * lowR) + (C1 * midR + C2 * midR);
		float b2 = highPot * (C1 * C2 * highR * R1 + C1 * C3 * highR * R1) - pow(midPot, 2)  *  (C1  *  C3  *  pow(midR, 2) + C2  *  C3  *  pow(midR, 2))
				+ midPot * (C1 * C3 * highR * midR + C1  *  C3  *  pow(midR ,2) + C2  *  C3  *  pow(midR, 2))
				+ lowPot * (C1 * C2 * highR * lowR + C1 * C2 * lowR * R1 + C1 * C3 * lowR * R1)
				+ lowPot * midPot * (C1 * C3 * lowR * midR + C2 * C3 * lowR * midR)
				+ (C1 * C2 * highR * midR + C1 * C2 * midR * R1 + C1 * C3 * midR * R1);
		float b3 = lowPot*midPot*(C1*C2*C3*highR*lowR*midR + C1*C2*C3*lowR*midR*R1)
				- pow(midPot, 2) * (C1 * C2 * C3 * highR * pow(midR, 2) + C1 * C2 * C3 * pow(midR, 2) * R1)
				+ midPot * (C1 * C2 * C3 * highR * pow(midR, 2) + C1 * C2 * C3 * pow(midR, 2) * R1)
				+ highPot * C1 * C2 * C3 * highR * midR * R1 - highPot * midPot * C1 * C2 * C3 * highR * midR * R1
				+ highPot * lowPot * C1 * C2 * C3 * highR * lowR * R1;
		float a0 = 1;
		float a1 = (C1*highR + C1*midR + C2*midR + C2*R1 + C3*R1) + midPot*C3*midR
				+ lowPot*(C1*lowR + C2*lowR);
		float a2 = midPot * (C1 * C3 * highR * midR - C2 * C3 * midR * R1 + C1 * C3 * pow(midR, 2) + C2 * C3 * pow(midR, 2))
				+ lowPot * midPot * (C1 * C3 * lowR * midR + C2 * C3 * lowR * midR)
				- pow(midPot, 2) * (C1 * C3 * pow(midR, 2) + C2 * C3 * pow(midR, 2))
				+ lowPot * (C1 * C2 * lowR * R1 + C1 * C2 * highR * lowR + C1 * C3 * lowR * R1 + C2 * C3 * lowR * R1)
				+ (C1 * C2 * highR * R1 + C1 * C3 * highR * R1 + C1 * C2 * midR * R1 + C1 * C2 * highR * midR
				+ C1 * C3 * midR * R1 + C2 * C3 * midR * R1);
		float a3 = lowPot * midPot * (C1 * C2 * C3 * highR * lowR * midR + C1 * C2 * C3 * lowR * midR * R1)
				- pow(midPot, 2) * (C1 * C2 * C3 * highR * pow(midR, 2) + C1 * C2 * C3 * pow(midR, 2) * R1)
				+ midPot * (C1 * C2 * C3 * pow(midR, 2) * R1 + C1 * C2 * C3 * highR * pow(midR, 2)
				- C1 * C2 * C3 * highR * midR * R1) + lowPot * C1 * C2 * C3 * highR * lowR * R1 + C1 * C2 * C3 * highR * midR * R1;

		B0 = -b1 * c - b2 * pow(c ,2) - b3 * pow(c ,3);
		B1 = -b1 * c + b2 * pow(c ,2) + 3 * b3 * pow(c ,3);
		B2 = b1 * c + b2 * pow(c , 2) - 3 * b3 * pow(c ,3);
		B3 = b1 * c - b2 * pow(c , 2) + b3 * pow(c , 3);
		A0 = -a0 - a1 * c - a2 * pow(c , 2) - a3 * pow(c , 3);
		A1 = -3 * a0 - a1 * c + a2 * pow(c , 2) + 3 * a3 * pow(c , 3);
		A2 = -3 * a0 + a1 * c + a2 * pow(c , 2) - 3 * a3 * pow(c , 3);
		A3 = -a0 + a1 * c - a2 * pow(c , 2) + a3 * pow(c , 3);
	}

	prevIn[3] = inBufs[0][0];
	prevIn[4] = inBufs[0][1];
	prevIn[5] = inBufs[0][2];

	for(unsigned int i = 0; i <= 2; ++i){
		//float q = inBufs[0][i];

		float tmp1 = B0 + B1 * prevIn[5 - i] + B2 * prevIn[ 5 - i - 1] + B3 * prevIn[ 5 - i - 2];
		float tmp2 = A0 + A1 * prevIn[5 - i] + A2 * prevIn[ 5 - i - 1] + A3 * prevIn[ 5 - i - 2];

		outBufs[0][i] = tmp1 / tmp2;
	}

	for(unsigned int i = 3; i <= nframes; ++i){

		float tmp1 = B0 + B1 * inBufs[0][i] + B2 * inBufs[0][i - 1] + B3 * inBufs[0][i - 2];
		float tmp2 = A0 + A1 * inBufs[0][i] + A2 * inBufs[0][i - 1] + A3 * inBufs[0][i - 2];

		outBufs[0][i] = tmp1 / tmp2;
	}

	prevIn[2] = inBufs[0][nframes];
	prevIn[1] = inBufs[0][nframes - 1];
	prevIn[0] = inBufs[0][nframes - 2];

}

ToneStackEq::ToneStackEq(IDetector *newUserInput):
		IFX(newUserInput)
		{
	settings = std::vector<Setting>{
		Setting("low", userInput->getInputHandler(ControllerInput::pot2), 50, 0, 100),
		Setting("mid", userInput->getInputHandler(ControllerInput::pot3), 50, 0, 100),
		Setting("high", userInput->getInputHandler(ControllerInput::pot4), 50, 0, 100)};
	C1 = 250e-12;
	C2 = 22e-9;
	C3 = 22e-9;
	R1 = 56e3;
	lowR = 1e6;
	midR = 25e3;
	highR = 250e3;
	fs = 44.1e3;
}

ToneStackEq::~ToneStackEq(){
}

const std::string *ToneStackEq::getName(){
	return &ToneStackEq::nameFx;
}

std::vector<Setting> *ToneStackEq::getSettings(){

}



