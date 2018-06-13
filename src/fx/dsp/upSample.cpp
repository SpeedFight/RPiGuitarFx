/*
 * oversample.cpp
 *
 *  Created on: 1 cze 2018
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

#include <dsp/upSample.hpp>

 float a0[] ={1.0, 1.0, 1.0, 1.0};
 float a1[] ={-1.532549527556315460, -1.541912931587635870, -1.559137102169563250, -1.590986719096086690};
 float a2[] ={0.605547144169744089, 0.725814082622104006, 0.859941060548118696, 0.958632517575690013};
 float b0[] ={0.181020514440805469,  0.379032383743673040, 0.378063621232366420, 0.176513391010764381};
 float b1[] ={-0.258929154747165324, -0.498297487151820151, -0.331230357683883037, 0.166286711453722286};
 float b2[] ={0.181020514440805469, 0.379032383743673040, 0.378063621232366420, 0.176513391010764381};

 unsigned short order = 4;

UpDownSample::UpDownSample(audioSettings::SamplingMultiplier mult, unsigned int inputBufferSize):
	mult(mult),
	bufferSize(mult * inputBufferSize),
	interpolationFilter(new IIR(a0, a1, a2, b0, b1, b2, order,bufferSize)),
	antiAliasingFilter(new IIR(a0, a1, a2, b0, b1, b2, order,bufferSize))
{
		std::fill(output.begin(), output.end(), 0.0);
}

std::array<float,1024> *UpDownSample::up(JackCpp::AudioIO::audioBufVector inBufs){

	unsigned int k = 0;
	for (unsigned int i = 0; i < bufferSize;){

		output[i++] = inBufs[0][k++];

		for (int j = 0; j < mult - 1; ++j){
			output[i++] = 0.0;
		}
	}

	interpolationFilter->filter(output.data(), output.data());

	return &output;
}

void UpDownSample::down(JackCpp::AudioIO::audioBufVector outBufs){

	antiAliasingFilter-> filter(output.data(), output.data());

	unsigned int k = 0;
	for (int i = 0; i < bufferSize / mult ;) {
		outBufs[0][i++] = output[k]*0.123; //compensate gain
		k += mult ;
	}
}






