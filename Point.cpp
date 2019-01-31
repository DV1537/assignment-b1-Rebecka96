#include <iostream>
#include <string>
#include "Point.h"

Point::Point(double *xCoord, double *yCoord, int nrCounter)
{
    this-> xCoord = xCoord;
    this-> yCoord = yCoord;

    for(int i = 0; i < nrCounter / 2; i++)
    {
        this-> xCoord[i] = xCoord[i];
        this-> yCoord[i] = yCoord[i];
    }
}
std::string Point::getType()
{
    return "Point";
}

double Point::area()
{
    return defaultArea;
}

Position Point::position()
{
    Position temp;
    
    temp.xCoord = xCoord[0] + xCoord[1] / 2;
    temp.yCoord = yCoord[0] + yCoord[1] / 2;

    return temp;
}