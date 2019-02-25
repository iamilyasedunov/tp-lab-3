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
        return radius;
    }
double Circle::getFerence(){
        return ference;
    }
double Circle::getArea(){
        return area;
    }


