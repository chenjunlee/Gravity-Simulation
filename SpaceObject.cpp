 // author: Sean Dashner

 /* Modified by Tianyu Kang
  * setters and getters not work because they are not include in head file
  * so I mark all those stuffs
  */

#include "SpaceObject.h"

SpaceObject::SpaceObject()
{}

SpaceObject::SpaceObject(
							std::string planetName,
							double x,
							double y,
							double z,
							double mass,
							double x_speed,
							double y_speed,
							double z_speed,
							double radius,
							double red,
							double green,
							double blue,
							std::string type
						)
{

	_planetName = planetName;
	_x = x;
	_y = y;
	_z = z;
	_mass = mass;
	_x_speed = x_speed;
	_y_speed = y_speed;
	_z_speed = z_speed;
	_radius = radius;
	_red = red;
	_green = green;
	_blue = blue;
	_type = type;

}
// so many setters and getter
//---------------------------------------------------
/*
string SpaceObject::getPlanetName(){
	return _planetName;
}
string SpaceObject::setPlanetName(string name){
	_planetName = name;
}
double SpaceObject::get_x(){
	return _x;
}
void SpaceObject::set_x(double x){
	_x = x;
}
double SpaceObject::get_y(){
	return _y;
}
void SpaceObject::set_y(double y){
	_y = y;
}
double SpaceObject::get_z(){
	return _z;
}
void SpaceObject::set_z(double z){
	_z = z;
}
double SpaceObject::getMass(){
	return _mass;
}
void SpaceObject::setMass(double mass){
	_mass = mass;
}
double SpaceObject::get_x_speed(){
		return x_speed;
}
void SpaceObject::set_x_speed(double x){
	_x_speed = x;
}
double SpaceObject::get_y_speed(){
		return x_speed;
}
void SpaceObject::set_y_speed(double y){
	_y_speed = y;
}
double SpaceObject::get_z_speed(){
		return z_speed;
}
void SpaceObject::set_z_speed(double z){
	_z_speed = z;
}
double SpaceObject::getRadius(){
		return _radius;
}
void SpaceObject::setRadius(double x){
	_radius = x;
}
int SpaceObject::getRed(){
	return _red;
}
void SpaceObject::setRed(int red){
	_red = red;
}
int SpaceObject::getGreen(){
	return _green;
}
void SpaceObject::setGreen(int green){
	_green = green;
}
int SpaceObject::getBlue(){
	return _Blue;
}
void SpaceObject::setBlue(int blue){
	_blue = blue;
}
string SpaceObject::getType(){
	return _type;
}
string SpaceObject::setType(string t){
	_type = t;
}
//----------------------------------------------------
*/
