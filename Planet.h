/*
 * Planet.h
 *
 *  Created on: Apr 11, 2014
 *      Author: David Argueta
 */

#ifndef PLANET_H_
#define PLANET_H_

#include "SpaceObject.h"
#include <vector>

using namespace std;

class Planet {
public:
	Planet();
	Planet(SpaceObject spaceObject);
	virtual ~Planet();
	void addMoon(SpaceObject moon);
	bool hasMoon();
	SpaceObject &getSpaceObject();
	vector<SpaceObject> &getMoons();

private:
	SpaceObject planet;
	vector<SpaceObject> moons;
};

#endif /* PLANET_H_ */
