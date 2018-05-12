/*
 * adapterToCAPS.hpp
 *
 *  Created on: 11 maj 2018
 *      Author: SF
 */

#ifndef ADAPTERTOCAPS_HPP_
#define ADAPTERTOCAPS_HPP_

//caps
#include "basics.h"
#include <vector>

class adapterPlugin : public Plugin {
public:

	/* get port value, mapping inf or nan to 0 */
	inline sample_t getport_unclamped (int i)
		{
			return getport (i);
		}

	/* get port value and clamp to port range */
	inline sample_t getport (int i)
		{
			if(i < 0){
				i = 0;
			}else if (i > settings->size() -1){
				i = settings->size() -1;
			}
			return settings->at(i);
		}

	/*
	 * first elements is settings, then the last ones is inBuff, and outBuff(sometimes out is stereo)
	 */
	inline void setPorts(std::vector<float> *newSettings){
		settings = newSettings;

	}


private:
	std::vector<float> *settings;

};


#endif /* ADAPTERTOCAPS_HPP_ */
