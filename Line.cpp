#include <iostream>
#include <string>
#include "Line.h"

Line::Line(double *xCoord, double *yCoord, int nrCounter)
{
    this-> xCoord = xCoord;
    this-> yCoord = yCoord;
    
    for(int i = 0; i < nrCounter / 2; i++)
    {
        this-> xCoord[i] = xCoord[i];
        this-> yCoord[i] = yCoord[i];
    }
}

std::string Line::getType()
{
    return "Line";
}

double Line::area()
{
    return defaultArea;
}

Position Line::position()
{
    Position temp;
    temp.xCoord = xCoord[0] + xCoord[1] / 2;
    temp.yCoord = yCoord[0] + yCoord[1] / 2;

    return temp;
}