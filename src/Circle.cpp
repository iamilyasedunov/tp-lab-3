#include "Circle.h"

Circle::Circle (double rad){
        setRadius(rad);
    }
void Circle::setRadius(double new_radius){
        radius = new_radius;
        ference = (2.0*pi*radius);
        area = (pi*radius*radius);
    }
void Circle::setFerence(double new_ference){
        ference = new_ference;
        radius = (ference/(2*pi));
        area = (pi*radius*radius);
    }
void Circle::setArea(double new_area){
        area = new_area;
        radius = (sqrt(area/pi));
        ference = (2.0*pi*radius);
    }

double Circle::getRadius(){
        //cout<<" radius = "<<radius;
        return radius;
    }
double Circle::getFerence(){
        //cout<<" ference = "<<ference/10;
        //if (radius == 10)
          //  return ference - (fmod(ference,62.8));
        //else
            return ference;
    }
double Circle::getArea(){
        //cout<<" area = "<<area/1000;
        //if (radius == 10)
          //  return area  - fmod(area, 314);
        //else
            return area;
    }


