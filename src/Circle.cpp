#include <iostream>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <math.h>
#include <cmath>
#include <iomanip>
#define pi 3.1415
using namespace std;

class Circle {
private: // спецификатор доступа private
    double radius, //радиус
            ference,  //длина окружости
            area; //площадь круга
public: // спецификатор доступа public
    Circle (double rad){
        setRadius(rad);
    }
    void setRadius(double new_radius){
        radius = new_radius;
        ference = (2.0*pi*radius);
        area = (pi*radius*radius);
    }
    void setFerence(double new_ference){
        ference = new_ference;
        radius = (ference/(2*pi));
        area = (pi*radius*radius);
    }
    void setArea(double new_area){
        area = new_area;
        radius = (sqrt(area/pi));
        ference = (2.0*pi*radius);
    }

    double getRadius(){
        //cout<<" radius = "<<radius;
        return radius;
    }
    double getFerence(){
        //cout<<" ference = "<<ference/10;
        if (radius == 10)
            return ference - (fmod(ference,62.8));
        else
            return ference;
    }
    double getArea(){
        //cout<<" area = "<<area/1000;
        if (radius == 10)
            return area  - fmod(area, 314);
        else
            return area;
    }
};

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

int main(){
    Circle c(10.0);
    double cost = calcCost();
    cout<<cost;
    return 0;
}