#include "task1.h"

class Circle {
private: // спецификатор доступа private
    double radius, //радиус
            ference,  //длина окружости
            area; //площадь круга
public: // спецификатор доступа public
    Circle (double rad);

    void setRadius(double new_radius);
    void setFerence(double new_ference);
    void setArea(double new_area);


    double getRadius();
    double getFerence();
    double getArea();
};