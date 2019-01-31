#ifndef LINE_H
#define LINE_H
#include <iostream>
#include <string>
#include "Shape.h"

class Line : public Shape
{
    public:
        std::string getType();
        double area();
        Position position();
        Line(double xCoord[], double yCoord[], int nrCounter);
};

#endif