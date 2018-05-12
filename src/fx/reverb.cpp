/*
 * reverb.cpp
 *
 *  Created on: 11 maj 2018
 *      Author: SF
 */

#include "reverb.hpp"
#include "array"

const std::string Reverb::nameFx("Reverb");

void Reverb::process(jack_nframes_t nframes, JackCpp::AudioIO::audioBufVector inBufs, JackCpp::AudioIO::audioBufVector outBufs){
	//set params values
	jvReverb->ports = new sample_t * [6];

	float param1 = settings.at(0).getValue() / 10.0;
	float param2 = settings.at(1).getValue() / 10.0;
	float param3 = settings.at(2).getValue() / 10.0;

	jvReverb->ports[0] = &param1;
	jvReverb->ports[1] = &param2;
	jvReverb->ports[2] = &param3;

	//set in/out bufs
	jvReverb->ports[3] = &inBufs[0][0];
	jvReverb->ports[4] = &outBufs[0][0];
	jvReverb->ports[5] = &outBufs[0][0];

	if(jvReverb->first_run){
		jvReverb->activate();
		jvReverb->first_run = 0;
	}

	jvReverb->cycle(nframes);
}

Reverb::Reverb(IDetector *newUserInput):
		IFX(newUserInput),
		jvReverb(new JVRev())
		{
	settings = std::vector<Setting>{
		Setting("bandwidth", userInput->getInputHandler(ControllerInput::pot2), 5, 0, 10),
		Setting("t60 (s)", userInput->getInputHandler(ControllerInput::pot3), 10, 0, 56),
		Setting("blend", userInput->getInputHandler(ControllerInput::pot4), 5, 0, 10)};

	int fs = 44100;
	jvReverb->fs = fs;
	jvReverb->over_fs = 1./fs;
	jvReverb->normal = NOISE_FLOOR;
	jvReverb->first_run = 1;
	jvReverb->init();
}

Reverb::~Reverb(){
}

const std::string *Reverb::getName(){
	return &Reverb::nameFx;
}

std::vector<Setting> *Reverb::getSettings(){

}
