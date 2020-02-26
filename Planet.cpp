/*
 * Planet.cpp
 *	Used in order to house the planet and its respective moon(s).
 *
 *  Created on: Apr 11, 2014
 *      Author: David Argueta
 */

#include "Planet.h"

Planet::Planet() {
}

/**
 * Constructor that just stores the planet object
 */
Planet::Planet(SpaceObject spaceObject) {
	planet = spaceObject;

}

/**
 * Function to check if planet has moon(s).
 */
bool Planet::hasMoon(){
	return (moons.size() > 0);
}

/**
 * Add moon to this planet
 */
void Planet::addMoon(SpaceObject moon){
	moons.push_back(moon);
}

/**
 * Function that will get the planet object in order to get object info
 * @return The planet space object
 */
SpaceObject &Planet::getSpaceObject(){
	return planet;
}

/**
 * Function that will get the moon(s) that are associated with this planet
 *
 * @return A vector of space objects that represent a moon
 */
vector<SpaceObject> &Planet::getMoons(){
	return moons;
}

Planet::~Planet() {
	// TODO Auto-generated destructor stub
}

