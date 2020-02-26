/*
 * SolarSystem.h
 *
 *  Created on: Apr 10, 2014
 *      Author: David Argueta
 */



#ifndef SOLARSYSTEM_H_
#define SOLARSYSTEM_H_

#include <iostream>
#include <vector>
#include <map>
#include "SpaceObject.h"
#include "Planet.h"
#include <string.h>

using namespace std;


	// Using string constants in case we change wording (i.e. abbreviate Moon as M)
	const string MOON_TEXT = "Satellite";
	const int MOON_GAP = 5; //Used to ignore "Moon" and numbering in text file, MarsMoon1->Moon1 ignored
	const string SUN_TEXT = "Sun";
	const string PLANET_TEXT = "Planet";
	const string STAR_TEXT = "Star";

class SolarSystem {
public:

	SolarSystem();
	SolarSystem(vector<SpaceObject> &spaceObjects);
	virtual ~SolarSystem();
	void update(vector<SpaceObject> &spaceObjects);
	vector<Planet> &getPlanets();
	vector<SpaceObject> &getStars();
	SpaceObject getSun();
	vector<SpaceObject> &getEntireSystem();


private:
	vector<SpaceObject> entireSystem;
	vector<SpaceObject> spaceObjects;
	map<string, Planet> planets; // Need in order to lookup planets for moons
	vector<Planet> planetVector; //What is sent when planets are requested
	vector<SpaceObject> moons;
	vector<SpaceObject> stars;
	SpaceObject sun;

	void assignObjects();
	void assignMoons();
};

#endif /* SOLARSYSTEM_H_ */
