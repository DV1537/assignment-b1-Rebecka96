#ifndef POLYGON_H
#define POLYGON_H
#include <iostream>
#include <string>
#include "Shape.h"

class Polygon : public Shape
{
    private:
        int nrCounter;
    public:
        Polygon& operator=(const Polygon& otherPoly); //1:a
        Polygon operator+(const Polygon& otherPoly); //2:a
        std::string getType();
        double area();
        double circumference();
        Position position();
        bool isConvex();
        Polygon(double xCoord[], double yCoord[], int nrCounter);

        friend std::ostream& operator<<(std::ostream& os, const Polygon& other);
};

#endif
