/*
 * tube.cpp
 *
 *  Created on: 2 cze 2018
 *      Author: SF
 */

#include "tube.hpp"

const std::string Tube::nameFx("Tube");

void Tube::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){

	float gain = settings.at(0).getValue();
	float dist = settings.at(1).getValue();
	float Q = settings.at(2).getValue()/10.0;
	float rh = settings.at(3).getValue()/20.0;
	float rl = settings.at(4).getValue()/20.0;
	float mix = settings.at(5).getValue()/20.0;


//	for(unsigned int i = 0; i <= nframes; ++i){
//		std::cout<<"meanDelayTimeInSamples "<<meanDelayTimeInSamples<<std::endl;
//		std::cout<<"maxVariationDelayTimeInSamples "<<maxVariationDelayTimeInSamples<<std::endl;
//		std::cout<<"sinGen "<<tmp<<std::endl;

//		% function y=tube(x, gain, Q, dist, rh, rl, mix)
//		% Author: Bendiksen, Dutilleux, ZẀ olzer
//		% y=tube(x, gain, Q, dist, rh, rl, mix)
//		% "Tube distortion" simulation, asymmetrical function
//		% x - input
//		% gain - the amount of distortion, >0->
//		% Q - work point. Controls the linearity of the transfer
//		% function for low input levels, more negative=more linear
//		% dist - controls the distortions character, a higher number gives
//		% a harder distortion, >0
//		% rh - abs(rh)<1, but close to 1. Placement of poles in the HP
//		% filter which removes the DC component
//		% rl - 0<rl<1. The pole placement in the LP filter used to
//		% simulate capacitances in a tube amplifier
//		% mix - mix of original and distorted sound, 1=only distorted

		auto upsampledInput = upSampler->up(inBufs);
		upSampler->down(outBufs);



//		for(unsigned int i = 0; i <= nframes; ++i){
//			outBufs[0][i] = inBufs[0][i] * gain;
//		}
//
//		if (Q == 0.0){
//			for(unsigned int i = 0; i <= nframes; ++i){
//				outBufs[0][i] = outBufs[0][i]/(1 - expf(-dist * outBufs[0][i]));
//				if (outBufs[0][i] == Q){
//					outBufs[0][i] = 1.0/dist;
//				}
//			}
//		}else{
//			for(unsigned int i = 0; i <= nframes; ++i){
//				outBufs[0][i] = (outBufs[0][i] - Q) / (1.0 - expf(-dist * (outBufs[0][i] - Q)) + outBufs[0][i]/ (1.0 - expf(dist * outBufs[0][i])) );
//				if (outBufs[0][i] == Q){
//					outBufs[0][i] = 1.0/dist + outBufs[0][i]/ (1.0 - expf(dist * outBufs[0][i]));
//				}
//			}
//		}
//
//		for(unsigned int i = 0; i <= nframes; ++i){
//			outBufs[0][i] = outBufs[0][i] * 0.98;
//		}

//		y=mix*z*max(abs(x))/max(abs(z))+(1-mix)*x;
//		y=y*max(abs(x))/max(abs(y));
//		y=filter([1 -2 1],[1 -2*rh rh^2],y); %HP filter
//		y=filter([1-rl],[1 -rl],y); %LP filter
//
//
//
//
//		float delay = *delayLine->getPreviousFract(meanDelayTimeInSamples + maxVariationDelayTimeInSamples * sinGen->getSample());
//		float xh;
//		xh = inBufs[0][i]+ FB * delay;
//		delayLine->toBuffer(xh);
//		outBufs[0][i] = FF * delay + BL * xh * 0.98;
//	}

}
//max delay 2**11 samples
//if fs = 44100, then this time is 0.046 s
//if fs = 48000, then this time is 0.042 s
//max delay 2**12 samples
//if fs = 44100, then this time is 0.092 s
//if fs = 48000, then this time is 0.085 s
Tube::Tube(IDetector *newUserInput):
		IFX(newUserInput),
		upSampler(new UpDownSample(audioSettings::x8, audioSettings::buffSize))
		{
	settings = std::vector<Setting>{
		Setting("gain", userInput->getInputHandler(ControllerInput::pot2), 5, 1, 50),
		Setting("dist type", userInput->getInputHandler(ControllerInput::pot3), 2, 1, 50),
		Setting("bias", userInput->getInputHandler(ControllerInput::pot4), 0, -10, 10),
		Setting("rh", userInput->getInputHandler(ControllerInput::pot6), 18, 1, 20),
		Setting("rl", userInput->getInputHandler(ControllerInput::pot7), 10, 1, 20),
		Setting("mix", userInput->getInputHandler(ControllerInput::pot8), 18, 1, 20)
	};
}

Tube::~Tube(){
}

const std::string *Tube::getName(){
	return &Tube::nameFx;
}

std::vector<Setting> *Tube::getSettings(){

}



