/*
 * SolarSystem.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: David Argueta
 *
 *      This class will take in space objects retrieved by parser.
 *      It will assign break out the space objects by planets and then assign
 *      any moons to it.
 *
 *      It will also house the information of the size of the solar system and have
 *      a reference to the sun, which is just another space object
 */

#include "SolarSystem.h"

SolarSystem::SolarSystem(){

}

/**
 * Constructor that will add the space objects to the system
 * and will also assign them to their respective groups
 */
SolarSystem::SolarSystem(vector<SpaceObject> &spaceObjects) {

	this->spaceObjects = spaceObjects;
	assignObjects();
	assignMoons();

}

SolarSystem::~SolarSystem() {
	// TODO Auto-generated destructor stub
}

/**
 * Function that will update the system with the given space objects
 */
void SolarSystem::update(vector<SpaceObject> &spaceObjects){
	this->spaceObjects = spaceObjects;
	assignObjects();
	assignMoons();
}

/**
 * Function that will return the vector of planets in this system
 */
vector<Planet> &SolarSystem::getPlanets(){
	//TODO
	return planetVector;
}

/**
 * Will return the sun for this solar system
 */
SpaceObject SolarSystem::getSun(){
	return sun;
}

/**
 * Will return the stars of this solar system.
 */
vector<SpaceObject> &SolarSystem::getStars(){
	return stars;
}

/**
 * Will return a vector of all the space objects in this system.
 */
vector<SpaceObject> &SolarSystem::getEntireSystem(){
	return spaceObjects;
}

/**
 * Helper function that will go through space objects and add them to appropriate list
 * of either planets, moons, or stars based on the objects type
 *
 */
void SolarSystem::assignObjects(){
	planets.clear();
	moons.clear();
	stars.clear();
	for(std::vector<SpaceObject>::iterator object = spaceObjects.begin(); object != spaceObjects.end(); ++object){

		if(object->_type == PLANET_TEXT)
			planets.insert( pair<string, Planet>(object->_planetName,Planet(*object)));

		if(object->_type == MOON_TEXT)
			moons.push_back(*object);

		if(object->_type == STAR_TEXT && object->_planetName == SUN_TEXT)
			sun = *object;

		if(object->_type == STAR_TEXT )
			stars.push_back(*object);


	}


}

/**
 * This will look through the parser results and match moons to their corresponding
 * planet. It will also add the planets to the planet vector with the updated moon info.
 */
void SolarSystem::assignMoons(){
	string planet("");
	map<string, Planet>::iterator found;

	for(std::vector<SpaceObject>::iterator moon = moons.begin(); moon != moons.end(); ++moon){
		planet.append(moon->_planetName.substr(0, moon->_planetName.size()- MOON_GAP));
		found = planets.find(planet);
		if(found == planets.end()){
			cerr << "not found: " << planet << endl;
		}
		else
			found->second.addMoon(*moon); // Adding moon to planet
	}

	planetVector.clear();
	for(std::map<string, Planet>::iterator planet = planets.begin(); planet != planets.end(); ++planet){
		planetVector.push_back(planet->second);

	}
}

