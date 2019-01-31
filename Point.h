#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <string>
#include "Shape.h"

class Point : public Shape
{
    public:
        std::string getType();
        double area();
        Position position();
        Point(double xCoord[], double yCoord[], int nrCounter); //constructor
};

#endif