#include <iostream>
#include <string>
#include "Polygon.h"
#include <cmath>

Polygon::Polygon(double *xCoord, double *yCoord, int nrCounter)
{
    this-> xCoord = new double [nrCounter / 2];
    this-> yCoord = new double [nrCounter / 2];
    this-> nrCounter = nrCounter;

    for(int i = 0; i < nrCounter / 2; i++)
    {
        this-> xCoord[i] = xCoord[i];
        this-> yCoord[i] = yCoord[i];
    }
}

std::string Polygon::getType() //{return "Polygon"};
{
    return "Polygon";
}

double Polygon::area()
{   
    double area = 0.0;
    int j = (nrCounter / 2) - 1;

    for(int i = 0; i < nrCounter / 2; i++)
    {
        area += (xCoord[j] + xCoord[i]) * (yCoord[j] - yCoord[i]);
        j = i;
    }

    area = std::abs(area / 2.0);
    
    return area;
}

double Polygon::circumference()
{
    double circumference = 0.0, circumX, circumY;

    for(int i = 0; i < nrCounter; i++)
    {
        circumX = xCoord[(i + 1) % nrCounter] - xCoord[i];
        circumY = yCoord[(i + 1) % nrCounter] - yCoord[i];
        circumference += sqrt(circumX * circumX + circumY * circumY);
    }

    return circumference;
}

Position Polygon::position()
{
    Position temp;

    for(int i = 0; i < nrCounter / 2; i++)
    {
        temp.xCoord += xCoord[i];
        temp.yCoord += yCoord[i];
    }

    temp.xCoord /= (nrCounter / 2);
    temp.yCoord /= (nrCounter / 2);

    return temp;
}

bool Polygon::isConvex()
{
    if((nrCounter / 2) < 4)
        return true;
    bool notTrue = false;

    int n = nrCounter / 2;

    for(int i = 0; i < n; i++)
    {
        double dx1 = xCoord[(i + 2) % n] - xCoord[(i + 1) % n];
        double dy1 = yCoord[(i + 2) % n] - yCoord[(i + 1) % n];
        double dx2 = xCoord[i] - xCoord[(i + 1) % n];
        double dy2 = yCoord[i] - yCoord[(i + 1) % n];
        double product = dx1 * dy2 - dy1 * dx2;

        if(i == 0)
            notTrue = product > 0;
        else if(notTrue != (product > 0))
            return defaultArea;
    }

    return true;
}
//A3 begins here
Polygon& Polygon::operator=(const Polygon & otherPoly)
{
    if (this == &otherPoly)
        return *this;

    delete[] xCoord;
    delete[] yCoord;
 
    nrCounter = otherPoly.nrCounter;

    if (otherPoly.xCoord)
    {
        xCoord = new double[nrCounter];
        yCoord = new double[nrCounter];
 
        for (int i = 0; i < nrCounter; ++i)
        {
            xCoord[i] = otherPoly.xCoord[i];
            yCoord[i] = otherPoly.yCoord[i];
        }
    }
    else
    {
        xCoord = 0;
        yCoord = 0;
    }
 
    return *this;
}

Polygon Polygon::operator+(const Polygon& otherPoly)
{
    int size = this-> nrCounter + otherPoly.nrCounter;
    int counter = 0;
    int splitter = (this-> nrCounter) / 2;

    double tempXcoord[size]; //om felmeddelande ända till dynamiskt allokerat minne
    double tempYcoord[size];

    for(int i = 0; i < size; i++)
    {
        if(i < splitter)
        {
            tempXcoord[i] = this-> xCoord[i];
            tempYcoord[i] = this-> yCoord[i];
        }else
        {
            tempXcoord[i] = otherPoly.xCoord[counter];
            tempYcoord[i] = otherPoly.yCoord[counter];

            counter++;
        }    
    }

    Polygon polygon(tempXcoord, tempYcoord, size);
    
    return polygon;
}

std::ostream& operator<<(std::ostream& os, const Polygon& other)
{
    for(int i = 0; i < other.nrCounter; i++)
    {
        os << "(" << other.xCoord[i] << "," << other.yCoord[i] << ")" << std::endl;
    }

    return os;
}