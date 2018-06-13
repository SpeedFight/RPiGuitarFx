/*
 * audio.cpp
 *
 *  Created on: 23 mar 2018
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

#include "audio.hpp"

Audio::Audio(FXList *newFxList) : JackCpp::AudioIO("RPiGuitarFX", 2,2), fxList(newFxList){
	start();

#ifdef DEBUG_INFO
	// reporting some client info
	std::cout << std::endl << "my name: " << input->getName() << std::endl;

	// test to see if it is real time
	if (input->isRealTime())
		std::cout << "is realtime " << std::endl;
	else
		std::cout << "is not realtime " << std::endl;

	//count the number of physical source and destination ports
	std::cout << "num physical source ports " << input->numPhysicalSourcePorts() << std::endl;
	std::cout << "num physical destination ports " << input->numPhysicalDestinationPorts() << std::endl;
#endif

	//connect our ports to physical ports
	connectToPhysical(0,0);		// connects this client out port 0 to physical destination port 0
	connectFromPhysical(0,0);	// connects this client in port 0 to physical source port 0

	//stereo
    connectToPhysical(1,1);		// connects this client out port 0 to physical destination port 0
	connectFromPhysical(1,1);	// connects this client in port 0 to physical source port 0

#ifdef DEBUG_INFO
	// port connection status
	std::cout << std::endl;
	std::cout << "output 0 is connected to " << input->numConnectionsOutPort(0) << " ports" << std::endl;
	std::cout << "input 0 is connected to " << input->numConnectionsInPort(0) << " ports" << std::endl;

	//print names
	std::cout << std::endl;
	std::cout << "inport names:" << std::endl;
	for(unsigned int i = 0; i < input->inPorts(); i++)
		cout << "\t" << input->getInputPortName(i) << std::endl;

	std::cout << "outport names:" << std::endl;
	for(unsigned int i = 0; i < input->outPorts(); i++)
		std::cout << "\t" << input->getOutputPortName(i) << std::endl;
#endif

}
//TODO fix buffers
int Audio::audioCallback(jack_nframes_t nframes, audioBufVector inBufs, audioBufVector outBufs){

//			auto start_audio_calback = std::chrono::steady_clock::now();
z
			for (auto& fxs : *fxList->getCurrentFXList()){
				fxs->process(nframes, inBufs, outBufs);

				inBufs = outBufs;
			}
			fxList->updateFXList();

//			auto end_audio_calback = std::chrono::steady_clock::now();
//			auto diff = end_audio_calback - start_audio_calback;
//			auto diff_u = std::chrono::duration_cast<std::chrono::microseconds>(diff);
//			std::cout << "diff micro:"<<diff_u.count() << std::endl;
			return 0;
}

Audio::~Audio(){
	disconnectInPort(0);	// Disconnecting ports
	disconnectOutPort(1);
	close();	// stop client.
}
