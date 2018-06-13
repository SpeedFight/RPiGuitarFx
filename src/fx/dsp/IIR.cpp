/*
 * IIR.cpp
 *
 *  Created on: 3 cze 2018
 *      Author: SF
 */

/*
RPiGuitarFx
Copyright (C) 2018  SpeedFight

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "IIR.hpp"

IIR::IIR(float *aa0, float *aa1, float *aa2, float *bb0, float *bb1, float *bb2, unsigned short newOrder, unsigned int newInputSize):
a0(aa0),
a1(aa1),
a2(aa2),
b0(bb0),
b1(bb1),
b2(bb2),
order(newOrder),
inputSize(newInputSize)
{
	   regX1.fill(0.0);
	   regX2.fill(0.0);
	   regY1.fill(0.0);
	   regY2.fill(0.0);
}

void IIR::filter(JackCpp::AudioIO::audioBufVector input, JackCpp::AudioIO::audioBufVector output){
	 float y;
	 unsigned int j, k;

	 for(j=0; j < audioSettings::buffSize; j++){
	   y = sectCalcForm1(0, input[0][j]);
	   for(k=1; k<order; k++){
		 y = sectCalcForm1(k, y);
		}
	   output[0][j] = y;
	  }
}

void IIR::filter(float* input, float* output){
	 float y;
	 unsigned int j, k;

	 for(j=0; j < inputSize; j++){
	   y = sectCalcForm1(0, input[j]);
	   for(k=1; k<order; k++){
		 y = sectCalcForm1(k, y);
		}
	   output[j] = y;
	  }
}

void IIR::setNewParams(float *aa0, float *aa1, float *aa2, float *bb0, float *bb1, float *bb2, unsigned short newOrder){
	a0 = aa0;
	a1 = aa1;
	a2 = aa2;
	b0 = bb0;
	b1 = bb1;
	b2 = bb2;
	order = newOrder;
}

inline float IIR::sectCalcForm1(unsigned short k, float x)
{
	float y, CenterTap;
 CenterTap = x * b0[k] + b1[k] * regX1[k] + b2[k] * regX2[k];
 y = a0[k] * CenterTap - a1[k] * regY1[k] - a2[k] * regY2[k];

 regX2[k] = regX1[k];
 regX1[k] = x;
 regY2[k] = regY1[k];
 regY1[k] = y;

 return(y);
}
