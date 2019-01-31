#include <iostream>
#include <string>
#include "Triangle.h"
#include <cmath>

Triangle::Triangle(double *xCoord, double *yCoord, int nrCounter)
{
    this-> xCoord = new double [nrCounter / 2];
    this-> yCoord = new double [nrCounter / 2];

    for(int i = 0; i < nrCounter / 2; i++)
    {
        this-> xCoord[i] = xCoord[i];
        this-> yCoord[i] = yCoord[i];
    }
}

std::string Triangle::getType()
{
    return "Triangle";
}

double Triangle::area() //Ax(By-Cy)+Bx(Cy-Ay)+Cx(Ay-By) / 2//double area = xCoord[0] * (yCoord[1] - yCoord[2]) + xCoord[1] * (yCoord[2] - yCoord[0]) + xCoord[2] * (yCoord[0] - yCoord[1]) / 2;
{
    double area = ((xCoord[1] - xCoord[0]) * (yCoord[2] - yCoord[0]) - (xCoord[2] - xCoord[0]) * (yCoord[1] - yCoord[0])) / 2.0;

    return area;
}

double Triangle::circumference()
{
    double circumferenceX = pow(xCoord[0] - xCoord[1], 2) + pow(yCoord[0] - yCoord[2], 2);
    double circumferenceY = pow(xCoord[1] - xCoord[2], 2) + pow(yCoord[1] - yCoord[2], 2);
    double circumferenceZ = pow(xCoord[2] - xCoord[0], 2) + pow(yCoord[2] - yCoord[0], 2);

    double circumference = circumferenceX + circumferenceY + circumferenceZ;

    return circumference;
}

Position Triangle::position() //Ox = Ax+Bx+Cx / 3, Oy = Ay+By+Cy / 3
{
    Position temp;
    temp.xCoord = (xCoord[0] + xCoord[1] + xCoord[2]) / 3;
    temp.yCoord = (yCoord[0] + yCoord[1] + yCoord[2]) / 3;

    return temp;
}

