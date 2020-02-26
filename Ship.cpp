/*
 * Ship.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: David Argueta
 */

#include "Ship.h"

Ship::Ship() {

	createShip();

}

Ship::~Ship() {
	// TODO Auto-generated destructor stub
}

void Ship::createShip(){
	createBody();
	createWindow();
}

/**
 * Would be used if ship view is changed
 * CURRENTLY NOT FULLY IMPLEMENTED
 */
void Ship::createBody(){
	Vector bottomRight(1,1,1);
	Vector topRight(1,1,-1);
	Vector topLeft(-1,1,-1);
	Vector bottomLeft(-1, 1, 1);
	Side top(topLeft, bottomLeft, topRight, bottomRight);

	Vector bottomRight1(1,1,1);
	Vector topRight1(-1,1,1);
	Vector topLeft1(-1,-1,1);
	Vector bottomLeft1(1, -1, 1);
	Side front(topLeft1, bottomLeft1, topRight1, bottomRight1);

	Vector bottomRight2(1,1,1);
	Vector topRight2(1,-1,1);
	Vector topLeft2(1,-1,-1);
	Vector bottomLeft2(1, 1, -1);
	Side right(topLeft2, bottomLeft2, topRight2, bottomRight2);

	Vector bottomRight3(-1,1,1);
	Vector topRight3(-1,1,-1);
	Vector topLeft3(-1,-1,-1);
	Vector bottomLeft3(-1, -1, 1);
	Side left(topLeft3, bottomLeft3, topRight3, bottomRight3);

	//GLdouble bottomRight4[] = {-1,1,1};
	Vector topRight4(1,1,1);
	Vector topLeft4(-1,1,1);
	Vector bottomLeft4(-0.75, -1,1);
	Vector bottomRight4(0.75,-1,1);
	Side back(topLeft4, bottomLeft4, topRight4, bottomRight4);

	Vector bottomRight5(1,1,-1);
	Vector topRight5(1,-1,-1);
	Vector topLeft5(-1,-1,-1);
	Vector bottomLeft5(-1, 1,-1);
	Side bottom(topLeft5, bottomLeft5, topRight5, bottomRight5);

	Shape result(front, right, left, back, top, bottom);
	body = &result;
}

/**
 * Consists of creating:
 * Screens, panels, and support beams
 *
 * Created based on set coordinates and then using
 * rendering method in order to resize and move
 */
void Ship::createWindow(){

	createScreens();

	Vector topRight(-2,1,1);
	Vector topLeft(-2,1,1);
	Vector bottomLeft(-2.75,1.25, 4.25);
	Vector bottomRight(-1,3,6.5);
	Side leftTopSidePanel(topLeft, bottomLeft, topRight, bottomRight);
	topSidePanel[0] = leftTopSidePanel;

	Vector topRight2(-2,1,1);
	Vector topLeft2(-2,1,1);
	Vector bottomLeft2(-1, 3, 6.5);
	Vector bottomRight2(-1.75,-1,1.5);
	Side leftInsidePanel(topLeft2, bottomLeft2, topRight2, bottomRight2);
	insideSidePanel[0] = leftInsidePanel;

	Vector topRight1(2,1,1);
	Vector topLeft1(-2,1,1);
	Vector bottomLeft1(-1.75, -1, 1.5);
	Vector bottomRight1(1.75,-1,1.5);
	Side fPanel(topLeft1, bottomLeft1, topRight1, bottomRight1);
	frontPanel = fPanel;


	Vector topRight3(2,1,1);
	Vector topLeft3(2,1,1);
	Vector bottomLeft3(1,3,6.5);
	Vector bottomRight3(2.75,1.25,4.25);
	Side rightTopSidePanel(topLeft3, bottomLeft3, topRight3, bottomRight3);
	topSidePanel[1] = rightTopSidePanel;

	Vector topRight4(2,1,1);
	Vector topLeft4(2,1,1);
	Vector bottomLeft4(1.75, -1, 1.5);
	Vector bottomRight4(1,3,6.5);
	Side rightInsidePanel(topLeft4, bottomLeft4, topRight4, bottomRight4);
	insideSidePanel[1] = rightInsidePanel;

	Vector topRight5(-.8,4.6,7.25);
	Vector topLeft5(-1.40,4.05,6.25);
	Vector bottomLeft5(-2, 1, 1);
	Vector bottomRight5(-1.25,1,1);
	Side leftSupportBeam(topLeft5, bottomLeft5, topRight5, bottomRight5);
	supportBeams[0] = leftSupportBeam;

	Vector topRight6(.8,4.6,7.25);
	Vector topLeft6(1.40,4.05,6.25);
	Vector bottomLeft6(2, 1, 1);
	Vector bottomRight6(1.25,1,1);
	Side rightSupportBeam(topLeft6, bottomLeft6, topRight6, bottomRight6);
	supportBeams[1] = rightSupportBeam;


}

void Ship::createScreens(){
	createMediumScreen();
	createLargeScreen();
}

void Ship::createLargeScreen(){
	Vector topRight(1.2,1,1);
	Vector topLeft(1.9,1,1);
	Vector bottomLeft(1.9,1 , 1.5);
	Vector bottomRight(1.2,1,1.5);
	Side top(topLeft, bottomLeft, topRight, bottomRight);
	largeScreenTop = top;

	Vector topRight1(1.2,1,1.5);
	Vector topLeft1(1.9,1,1.5);
	Vector bottomLeft1(1.9,.2 , 1.5);
	Vector bottomRight1(1.2,.2,1.5);
	Side front(topLeft1, bottomLeft1, topRight1, bottomRight1);
	largeScreenFront = front;

	Vector topRight2(1.2,1,1);
	Vector topLeft2(1.2,1,1.5);
	Vector bottomLeft2(1.2,.2,1.5);
	Vector bottomRight2(1.2,.2,1);
	Side left(topLeft2, bottomLeft2, topRight2, bottomRight2);
	largeScreenLeft = left;
}

void Ship::createMediumScreen(){
	Vector topRight(-1.3,.8,1);
	Vector topLeft(-1.8,.8,1);
	Vector bottomLeft(-1.8,.8 , 1.5);
	Vector bottomRight(-1.3,.8,1.5);
	Side top(topLeft, bottomLeft, topRight, bottomRight);
	mediumScreenTop = top;

	Vector topRight1(-1.3,.8,1.5);
	Vector topLeft1(-1.8,.8,1.5);
	Vector bottomLeft1(-1.8,.2 , 1.5);
	Vector bottomRight1(-1.3,.2,1.5);
	Side front(topLeft1, bottomLeft1, topRight1, bottomRight1);
	mediumScreenFront = front;

	Vector topRight2(-1.3,.8,1);
	Vector topLeft2(-1.3,.8,1.5);
	Vector bottomLeft2(-1.3,.2,1.5);
	Vector bottomRight2(-1.3,.2,1);
	Side right(topLeft2, bottomLeft2, topRight2, bottomRight2);
	mediumScreenRight = right;
}

// Used in order to set the color of the ship
void Ship::setColors(GLfloat surfaceColor[], GLfloat specularColor[], GLfloat emissionColor[],
		float eMultiplier, double r, double g, double b){
    surfaceColor[0] =r;
	surfaceColor[1] =g;
	surfaceColor[2] =b;
	specularColor[0] =r;
	specularColor[1] =g;
	specularColor[2] =b;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, surfaceColor);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 3.0f);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularColor);

	emissionColor[0] =r*eMultiplier;
	emissionColor[1] =g*eMultiplier;
	emissionColor[2] =b*eMultiplier;
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emissionColor);

}

// used to draw the main view of ship
void Ship::renderWindow(){
	double r, g, b, base = 160.0;

	glLoadIdentity();

	//Move the model down y by 7.5 and depth by 9.55
	glTranslatef(0,-7.5, -9.55);

	//Scale the model
	glScalef(7.4f, 5.5f, 1.0f);

	//Rotate the model
	glRotated(20,1,0,0); // 20 degrees around x-axis
	glNormal3d( 0, 0, 1 ); // front polygon normal

	// Used for color
	GLfloat surfaceColor[4];
	GLfloat emissionColor[4];
	GLfloat specularColor[4];
	surfaceColor[3]=1.0f;
	emissionColor[3]=1.0f;
	specularColor[3]=1.0f;

	r = g = b = (base + 32.0) /255.0; //Shade of gray
	setColors(surfaceColor, specularColor, emissionColor, 0.03f,r, g, b);

	//Top left side panel
	glBegin(GL_POLYGON);
	glVertex3dv(topSidePanel[0].topRightPoint().getVector());
	glVertex3dv(topSidePanel[0].topLeftPoint().getVector());
	glVertex3dv(topSidePanel[0].bottomLeftPoint().getVector());
	glVertex3dv(topSidePanel[0].bottomRightPoint().getVector());
	glEnd();

	// Top right side panel
	glBegin(GL_POLYGON);
	glVertex3dv(topSidePanel[1].topRightPoint().getVector());
	glVertex3dv(topSidePanel[1].topLeftPoint().getVector());
	glVertex3dv(topSidePanel[1].bottomLeftPoint().getVector());
	glVertex3dv(topSidePanel[1].bottomRightPoint().getVector());
	glEnd();

	// Inside left side panel
	r = g = b = (base+16.0) /255.0; //Shade of gray
	setColors(surfaceColor, specularColor, emissionColor, 0.03f,r, g, b);
	glBegin(GL_POLYGON);
	glVertex3dv(insideSidePanel[0].topRightPoint().getVector());
	glVertex3dv(insideSidePanel[0].topLeftPoint().getVector());
	glVertex3dv(insideSidePanel[0].bottomLeftPoint().getVector());
	glVertex3dv(insideSidePanel[0].bottomRightPoint().getVector());
	glEnd();

	// Inside right side panel
	glBegin(GL_POLYGON);
	glVertex3dv(insideSidePanel[1].topRightPoint().getVector());
	glVertex3dv(insideSidePanel[1].topLeftPoint().getVector());
	glVertex3dv(insideSidePanel[1].bottomLeftPoint().getVector());
	glVertex3dv(insideSidePanel[1].bottomRightPoint().getVector());
	glEnd();

	// Top left support beam
	glBegin(GL_POLYGON);
	glVertex3dv(supportBeams[0].topRightPoint().getVector());
	glVertex3dv(supportBeams[0].topLeftPoint().getVector());
	glVertex3dv(supportBeams[0].bottomLeftPoint().getVector());
	glVertex3dv(supportBeams[0].bottomRightPoint().getVector());
	glEnd();

	// Top right support beam
	glBegin(GL_POLYGON);
	glVertex3dv(supportBeams[1].topRightPoint().getVector());
	glVertex3dv(supportBeams[1].topLeftPoint().getVector());
	glVertex3dv(supportBeams[1].bottomLeftPoint().getVector());
	glVertex3dv(supportBeams[1].bottomRightPoint().getVector());
	glEnd();

	// Front Panel
	r = g = b = base/255.0;//Shade of gray
	setColors(surfaceColor, specularColor, emissionColor, 0.03f,r, g, b);
	glBegin(GL_POLYGON);
	glVertex3dv(frontPanel.topRightPoint().getVector());
	glVertex3dv(frontPanel.topLeftPoint().getVector());
	glVertex3dv(frontPanel.bottomLeftPoint().getVector());
	glVertex3dv(frontPanel.bottomRightPoint().getVector());
	glEnd();

	// Front of medium size screen
	r = g = b = (base-24.0)/255.0;//Shade of gray
	setColors(surfaceColor, specularColor, emissionColor, 0.03f,r, g, b);
	glBegin(GL_POLYGON);
	glVertex3dv(mediumScreenFront.topRightPoint().getVector());
	glVertex3dv(mediumScreenFront.topLeftPoint().getVector());
	glVertex3dv(mediumScreenFront.bottomLeftPoint().getVector());
	glVertex3dv(mediumScreenFront.bottomRightPoint().getVector());
	glEnd();

	// Front of large size screen
	glBegin(GL_POLYGON);
	glVertex3dv(largeScreenFront.topRightPoint().getVector());
	glVertex3dv(largeScreenFront.topLeftPoint().getVector());
	glVertex3dv(largeScreenFront.bottomLeftPoint().getVector());
	glVertex3dv(largeScreenFront.bottomRightPoint().getVector());
	glEnd();

	//Center Radar
	glBegin(GL_POLYGON);
	glVertex3d(.5, 1, 2);
	glVertex3d(.25, 1.25, 2);
	glVertex3d(-.25, 1.25, 2);
	glVertex3d(-.5, 1, 2);
	glVertex3d(-.5, .75, 2);
	glVertex3d(-.25, .5, 2);
	glVertex3d(.25, .5, 2);
	glVertex3d(.5, .75, 2);
	glEnd();

	// Top of medium size screen
	r = g = b = (base-16.0)/255.0;//Shade of gray
	setColors(surfaceColor, specularColor, emissionColor, 0.03f,r, g, b);
	glBegin(GL_POLYGON);
	glVertex3dv(mediumScreenTop.topRightPoint().getVector());
	glVertex3dv(mediumScreenTop.topLeftPoint().getVector());
	glVertex3dv(mediumScreenTop.bottomLeftPoint().getVector());
	glVertex3dv(mediumScreenTop.bottomRightPoint().getVector());
	glEnd();

	// Top of large size screen
	glBegin(GL_POLYGON);
	glVertex3dv(largeScreenTop.topRightPoint().getVector());
	glVertex3dv(largeScreenTop.topLeftPoint().getVector());
	glVertex3dv(largeScreenTop.bottomLeftPoint().getVector());
	glVertex3dv(largeScreenTop.bottomRightPoint().getVector());
	glEnd();

	// Right of medium size screen
	r = g = b = (base-8.0)/255.0;//Shade of gray
	setColors(surfaceColor, specularColor, emissionColor, 0.03f,r, g, b);
	glBegin(GL_POLYGON);
	glVertex3dv(mediumScreenRight.topRightPoint().getVector());
	glVertex3dv(mediumScreenRight.topLeftPoint().getVector());
	glVertex3dv(mediumScreenRight.bottomLeftPoint().getVector());
	glVertex3dv(mediumScreenRight.bottomRightPoint().getVector());
	glEnd();

	// Left of large size screen
	glBegin(GL_POLYGON);
	glVertex3dv(largeScreenLeft.topRightPoint().getVector());
	glVertex3dv(largeScreenLeft.topLeftPoint().getVector());
	glVertex3dv(largeScreenLeft.bottomLeftPoint().getVector());
	glVertex3dv(largeScreenLeft.bottomRightPoint().getVector());
	glEnd();


}


Ship::Shape Ship::getBody(){
	return *body;
}

Ship::Vector::Vector(){
	x = 0;
	y = 0;
	z = 0;
	vector[0] = x;
	vector[1] = y;
	vector[2] = z;
}

Ship::Vector::Vector(double newX, double newY, double newZ){
	x = newX;
	y = newY;
	z = newZ;
	vector[0] = x;
	vector[1] = y;
	vector[2] = z;
}
Ship::Vector::~Vector(){
}

/**
 * Retrieve point x
 */
GLdouble Ship::Vector::getX(){
	return x;
}

/**
 * Retrieve point y
 */
GLdouble Ship::Vector::getY(){
	return y;
}

/**
 * Retrieve point z
 */
GLdouble Ship::Vector::getZ(){
	return z;
}

GLdouble* Ship::Vector::getVector() {

	return vector;
}
/**
 * Update the points
 * @param x point x
 * @param y point y
 * @param z point z
 */
void Ship::Vector::update(double newX, double newY, double newZ){
	x = newX;
	y = newY;
	z = newZ;
	vector[0] = x;
	vector[1] = y;
	vector[2] = z;
}

Ship::Side::Side(){

}

/**
 * A side that will be used by the Shape
 *
 */
Ship::Side::Side(Vector topLeft, Vector bottomLeft, Vector topRight, Vector bottomRight){
	point[TOPLEFT] = topLeft;
	point[BOTTOMLEFT] = bottomLeft;
	point[TOPRIGHT] = topRight;
	point[BOTTOMRIGHT] = bottomRight;
}

Ship::Side::~Side(){

}

Ship::Vector Ship::Side::topLeftPoint(){
	return point[TOPLEFT];
}

Ship::Vector Ship::Side::bottomLeftPoint(){
	return point[BOTTOMLEFT];
}

Ship::Vector Ship::Side::topRightPoint(){
	return point[TOPRIGHT];
}

Ship::Vector Ship::Side::bottomRightPoint(){
	return point[BOTTOMRIGHT];
}

Ship::Shape::Shape(){

}

Ship::Shape::Shape(Side front, Side right, Side left, Side back, Side top, Side bottom){
	side[FRONT] = front;
	side[RIGHT] = right;
	side[LEFT] = left;
	side[BACK]	= back;
	side[TOP] = top;
	side[BOTTOM] = bottom;
}

Ship::Shape::~Shape(){

}

Ship::Side Ship::Shape::getFront(){
	return side[FRONT];
}

Ship::Side Ship::Shape::getRight(){
	return side[RIGHT];
}

Ship::Side Ship::Shape::getLeft(){
	return side[LEFT];
}

Ship::Side Ship::Shape::getBack(){
	return side[BACK];
}

Ship::Side Ship::Shape::getTop(){
	return side[TOP];
}

Ship::Side Ship::Shape::getBottom(){
	return side[BOTTOM];
}
