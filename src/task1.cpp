#include "task1.h"
#include "Circle.h"
#define pi 3.1415

double calcDelta(){
    double rad_of_Earth = 63781000.0, delta = 1.0; //in metres
    Circle c(rad_of_Earth);

    double act_ference = c.getFerence(); //actually ference for the Earth
    c.setFerence(act_ference + delta);   //new ference for rope
    double rad_rope_circle = c.getRadius();         //radius for circle made by rope

    double ans = rad_rope_circle - rad_of_Earth;
    return ans - ans/1000;                  //length of the gap
}

double calcCost() {
    double width_track = 1.0, rad_of_pool = 3.0;
    double cost_of_track = 1000.0, cost_of_fence = 2000.0;
    Circle c(rad_of_pool);
    double area1 = c.getArea();
    c.setRadius(rad_of_pool + width_track);
    double area2 = c.getArea();
    double ference = c.getFerence();

    return (area2 - area1)*cost_of_track + ference*cost_of_fence;
}
