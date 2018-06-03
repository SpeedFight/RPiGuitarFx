/*
 * IIR.hpp
 *
 *  Created on: 3 cze 2018
 *      Author: SF
 */

#ifndef IIR_HPP_
#define IIR_HPP_

#include "config.hpp"
#include <jackaudioio.hpp>

class IIR{
public:
	IIR(float *aa0, float *aa1, float *aa2, float *bb0, float *bb1, float *bb2, unsigned short newOrder, unsigned int newInputSize);
	void filter(JackCpp::AudioIO::audioBufVector input, JackCpp::AudioIO::audioBufVector output);
	void filter(float* input, float* output);
	void setNewParams(float *aa0, float *aa1, float *aa2, float *bb0, float *bb1, float *bb2, unsigned short newOrder);


private:
	float sectCalcForm1(unsigned short k, float x);

	 float *a0, *a1,  *a2,  *b0,  *b1,  *b2;
	 unsigned short order;
	 unsigned int inputSize;
	 std::array<float,18> regX1;
	 std::array<float,18> regX2;
	 std::array<float,18> regY1;
	 std::array<float,18> regY2;
};


#endif /* IIR_HPP_ */
