#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include <string>
#include "Shape.h"

class Triangle : public Shape
{
    public:
        std::string getType();
        double area();
        double circumference();
        Position position();
        Triangle(double xCoord[], double yCoord[], int nrCounter);

};

#endif