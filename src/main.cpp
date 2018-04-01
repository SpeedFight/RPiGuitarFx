/*
 * main.cpp
 *
 *  Created on: 23 mar 2018
 *      Author: SF
 */

#include "config.hpp"

#include "audio.hpp"
#include "effect.hpp"
#include <memory>
#include <iostream>

using namespace std;

int main( int argc, char * argv[] )
{
	unique_ptr<FXList> fxList(new FXList());

	fxList->getFXList()->push_back(shared_ptr<IFX>(new PlaybackFx()));

	unique_ptr<Audio> input = unique_ptr<Audio>(new Audio(fxList.get()));
	input->start();

		// reporting some client info
			cout << endl << "my name: " << input->getName() << endl;

			// test to see if it is real time
			if (input->isRealTime())
				cout << "is realtime " << endl;
			else
				cout << "is not realtime " << endl;

			//count the number of physical source and destination ports
			cout << "num physical source ports " << input->numPhysicalSourcePorts() << endl;
			cout << "num physical destination ports " << input->numPhysicalDestinationPorts() << endl;

			//connect our ports to physical ports
			input->connectToPhysical(0,0);		// connects this client out port 0 to physical destination port 0
			input->connectFromPhysical(0,0);	// connects this client in port 0 to physical source port 0

			// port connection status
				cout << endl;
				cout << "output 0 is connected to " << input->numConnectionsOutPort(0) << " ports" << endl;
				cout << "input 0 is connected to " << input->numConnectionsInPort(0) << " ports" << endl;

				//print names
				cout << endl;
				cout << "inport names:" << endl;
				for(unsigned int i = 0; i < input->inPorts(); i++)
					cout << "\t" << input->getInputPortName(i) << endl;

				cout << "outport names:" << endl;
				for(unsigned int i = 0; i < input->outPorts(); i++)
					cout << "\t" << input->getOutputPortName(i) << endl;

				sleep(10);		// sleep to allow the callback to run for 50 seconds.

				input->disconnectInPort(0);	// Disconnecting ports.
				input->disconnectOutPort(1);
				input->close();	// stop client.

				fxList.reset();
				input.reset();
    return 0;
}
