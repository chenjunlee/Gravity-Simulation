/*
 * Ship.h
 *
 *  Created on: Apr 16, 2014
 *      Author: David Argueta
 */

#ifndef SHIP_H_
#define SHIP_H_

#include <GL/gl.h>
#include <GL/glu.h>

class Ship {
	class Vector {
	public:
		Vector();
		Vector(double newX, double newY, double newZ);
		virtual ~Vector();
		GLdouble getX();
		GLdouble getY();
		GLdouble getZ();
		GLdouble* getVector();
		void update(double newX, double newY, double newZ);
	private:
		GLdouble x, y, z;
		GLdouble vector[3];

	};
	class Side {
	public:
		Side();
		Side(Vector topLeft, Vector bottomLeft, Vector topRight, Vector bottomRight);
		virtual ~Side();
		Vector topLeftPoint();
		Vector bottomLeftPoint();
		Vector topRightPoint();
		Vector bottomRightPoint();

	private:
		enum PointLabels {TOPLEFT = 0, BOTTOMLEFT, TOPRIGHT, BOTTOMRIGHT};
		Vector point[4];

	};
	class Shape {
	public:
		Shape();
		Shape(Side front, Side right, Side left, Side back, Side top, Side bottom);
		virtual ~Shape();
		Side getFront();
		Side getRight();
		Side getLeft();
		Side getBack();
		Side getTop();
		Side getBottom();


	private:
		enum SideLabels {FRONT = 0, RIGHT, LEFT, BACK, TOP, BOTTOM};
		Side side[6];

	};
public:
	Ship();
	virtual ~Ship();
	float size();
	Shape getBody();
	void renderWindow();

private:
	enum Position {TOPLEFT=0, BOTTOMLEFT, TOPRIGHT, BOTTOMRIGHT};
	Shape wings[];
	Shape *body;
	Shape nose;
	Shape thrusters[];
	Shape blasters[];
	Side frontPanel;
	Side mediumScreenTop;
	Side mediumScreenFront;
	Side mediumScreenRight;
	Side largeScreenTop;
	Side largeScreenFront;
	Side largeScreenLeft;
	Side supportBeams[2];
	Side topSidePanel[2];
	Side insideSidePanel[2];

	void createShip();
	void createBody();
	void createWindow();
	void createScreens();
	void createMediumScreen();
	void createLargeScreen();
	void setColors(GLfloat surfaceColor[], GLfloat specularColor[], GLfloat emissionColor[],
			float eMultiplier, double r, double g, double b);
};

#endif /* SHIP_H_ */
