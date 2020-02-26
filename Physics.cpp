 /* author: Tianyu Kang 
 	updated with comments, and collision support added by Sean Dashner
  * Class Physics
  * Final version - maybe :)
  */

#include "Physics.h"

//data conclude all planets' information
//position is in meters, speed is in meters per second
//mass is in kilograms
//interval is in seconds -- should be 1 for most accurate
Physics::Physics(){}

Physics::Physics(std::vector<SpaceObject> data,long interval){
		// this is the gravity constant
        G = 6.6738480e-11;
        // turn based right now
        currentStep = data;
        nextStep = data;
        this->interval = interval;
        xxxx  = 5e8;
    }

void Physics::step(){
    int n = currentStep.size();
    bool not_crashing = true;
    //calculate speed
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++) {
        	// our crash flag gets set equal to calc because that returns
        	// a boolean saying whether the two objects are touching
            not_crashing = calc(&currentStep[i],&currentStep[j],
                &nextStep[i],&nextStep[j]);
            if (!not_crashing){
            	currentStep[j]._mass += currentStep[i]._mass;
            	currentStep[j]._x_speed += currentStep[i]._x_speed;
            	currentStep[j]._y_speed += currentStep[i]._y_speed;
            	currentStep[j]._z_speed += currentStep[i]._z_speed;
            	currentStep[j]._radius += currentStep[i]._radius;

            	currentStep.erase(currentStep.begin());
            	nextStep.erase(nextStep.begin() + j);
            	

            	// erase currentStep[i] and nextStep[i]
            	// currentStep[j] and nextStep[j] become a conglomerate of the two
            	// add mass together, add each vector together.
            }

        }
    }
        //calculate position
    
	    for(int i=0;i<n;i++){
	        SpaceObject *cp = &currentStep[i];
	        SpaceObject *p = &nextStep[i];
	        p->_x += (p->_x_speed+cp->_x_speed)*interval/2;
	        p->_y += (p->_y_speed+cp->_y_speed)*interval/2;
	        p->_z += (p->_z_speed+cp->_z_speed)*interval/2;
	    }
	    currentStep = nextStep;
	
} 
/*
void Physics::step(){
    for (int i = 0; i < currentStep.size(); i++){
        SpaceObject *p = &currentStep[i];
        bool not_crashing = true;
        for (int j = 0; j < currentStep.size(); j++) {
            if (j == i || j >= 10000) {
                break;
            }

            const SpaceObject *p1 = &currentStep[j];

            double distance = sqrt(pow(p1->_x-p->_x,2)+pow(p1->_y-p->_y,2)+pow(p1->_z-p->_z,2));
            if (distance > p1->_radius){
                p->_x_speed += G * p1->_mass / (distance * distance) * (p1->_x - p->_x)/distance;
                p->_y_speed += G * p1->_mass / (distance * distance) * (p1->_y - p->_y)/distance;
                p->_z_speed += G * p1->_mass / (distance * distance) * (p1->_z - p->_z)/distance;

            } else {
                // something happens when they crash
                not_crashing = false;
            }

            if (not_crashing){
                p->_x += p->_x_speed;
                p->_y += p->_y_speed;
                p->_z += p->_z_speed;

            }
            else {
                // delete the object somehow
            }

        }
    }
}
*/

bool Physics::calc(SpaceObject *p1,SpaceObject *p2,SpaceObject *np1,SpaceObject *np2){
    // square root of x1 - x2 squared plus y1 - y2 squared plus z1 - z2 squared
    // gives us the three dimensional distance between the two objects
    double distance = sqrt(pow(p1->_x-p2->_x,2)+pow(p1->_y-p2->_y,2)+pow(p1->_z-p2->_z,2));
    
    
    	double radX = (p1->_x-p2->_x)/distance;
    	double radY = (p1->_y-p2->_y)/distance;
    	double radZ = (p1->_z-p2->_z)/distance;
    
    	double g = G/pow(distance,2);

    	double acc1 = g*p2->_mass;

   		np1->_x_speed -= acc1*radX*interval;
	    np1->_y_speed -= acc1*radY*interval;
	    np1->_z_speed -= acc1*radZ*interval;
	    double acc2 = g*p1->_mass;
	    np2->_x_speed += acc2*radX*interval;
	    np2->_y_speed += acc2*radY*interval;
	    np2->_z_speed += acc2*radZ*interval;

	
	// if the distance is greater than the two radii added together we do the calculation
    // and return true
    // else
    // we return false so the step function knows to implement the collision    
	if (distance > (1000 * p1->_radius/xxxx) + (1000*p2->_radius/xxxx)  ){
	    return true;
	} else {
		return false;
	}
}
