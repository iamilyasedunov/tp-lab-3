#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <queue>
#include <set>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

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