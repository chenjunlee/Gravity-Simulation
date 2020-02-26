// Gravity Sim Project
// Sean Dashner
// SpaceObject.h header file

 /* Modified by Tianyu Kang
  * setters and getters not work because they are not include in head file
  * so I just make all things public
  */

#ifndef SpaceObject_h
#define SpaceObject_h
#include <string>
class SpaceObject {

	public:
		std::string _planetName;
		double _x;
		double _y;
		double _z;
		double _mass;
		double _x_speed;
		double _y_speed;
		double _z_speed;
		double _radius;
		double _red;
		double _green;
		double _blue;
		std::string _type;

		// default constructor
		SpaceObject ();
		// initializing constructor for SpaceObject
		SpaceObject (
						std::string _planetName,
						double _x,
						double _y,
						double _z,
						double _mass,
						double _x_speed,
						double _y_speed,
						double _z_speed,
						double _radius,
						double _red,
						double _green,
						double _blue,
						std::string _type
					);
};
#endif
