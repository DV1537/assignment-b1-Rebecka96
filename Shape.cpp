#include <iostream>
#include <string>
#include "Shape.h"
#include <cmath>

//double Shape::getType()

//double Shape::area()

double Shape::circumreference() //circumreference() returns circumreference of the object
{
    return defaultArea;
}

//Position Shape::position()

bool Shape::isConvex() //isConvex() returns true if shape is convex
{
    return defaultArea;
}

double Shape::distance(Shape *s)
{
    Position XY1 = position();
    Position XY2 = s->position();
    double coordinatesX = XY1.xCoord - XY2.xCoord;
    double coordinatesY = XY1.yCoord - XY2.yCoord;

    double distance = hypot(coordinatesX, coordinatesY);

    return distance;
}