 /* author: Tianyu Kang
  * Class Physics
  * Final version - maybe :)
  */

#ifndef physics_h
#define physics_h
#include <math.h>
#include <vector>
#include "SpaceObject.h"

class Physics
{
    public:
    	float xxxx;
        double G;
        std::vector<SpaceObject> currentStep;
        std::vector<SpaceObject> nextStep;
        long interval;
        Physics();
        Physics(std::vector<SpaceObject> data,long interval);
        void step();
    private:
        bool calc(SpaceObject *p1,SpaceObject *p2,SpaceObject *np1,SpaceObject *np2);
};

#endif // physics_h
