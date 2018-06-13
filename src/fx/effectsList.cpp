/*
 * effectsList.cpp
 *
 *  Created on: 26 kwi 2018
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

#include "effectsList.hpp"

/**
 * @brief Always add new fx here
 * @param newUserInput pointer to controller object
 */
AvaibleFxList::AvaibleFxList(IDetector *newUserInput){
	fxlist.push_back(std::unique_ptr<IFX>(new PlaybackFx(newUserInput)));
	fxlist.push_back(std::unique_ptr<IFX>(new Clipper(newUserInput)));
	fxlist.push_back(std::unique_ptr<IFX>(new Fuzz(newUserInput)));
	fxlist.push_back(std::unique_ptr<IFX>(new ToneStackEq(newUserInput)));
	fxlist.push_back(std::unique_ptr<IFX>(new Delay(newUserInput)));
	fxlist.push_back(std::unique_ptr<IFX>(new Flanger(newUserInput)));
	fxlist.push_back(std::unique_ptr<IFX>(new Chorus(newUserInput)));
	fxlist.push_back(std::unique_ptr<IFX>(new Vibrato(newUserInput)));


}

/**
 * @brief Always add new fx here
 * @param fxNum num of effect to create
 * @param newUserInput pointer to controller object
 * @return pointer to new fx object
 */
IFX *FxFactory::createFx(int fxNum, IDetector *newUserInput){
	std::cout<<"fxNum "<<fxNum<<std::endl;
	switch (fxNum) {
		case 0: return new PlaybackFx(newUserInput); break; //playback FX always first!
		case 1: return new Clipper(newUserInput); break;
		case 2: return new Fuzz(newUserInput); break;
		case 3: return new ToneStackEq(newUserInput); break;
		case 4: return new Delay(newUserInput); break;
		case 5: return new Flanger(newUserInput); break;
		case 6: return new Chorus(newUserInput); break;
		case 7: return new Vibrato(newUserInput); break;

		default: return nullptr; break;
	}
}
