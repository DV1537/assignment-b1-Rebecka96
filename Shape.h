#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>

struct Position{
    double xCoord;
    double yCoord;
};

class Shape
{
    protected:
        int n;
        int defaultArea = -1; //arean för point, line och konkav
        double *xCoord;
        double *yCoord;
        int pointCounter;
        int nrCounter;
    public:
        virtual std::string getType() = 0;
        virtual double area() = 0;
        virtual double circumreference();
        virtual Position position() = 0;
        virtual bool isConvex();
        virtual double distance(Shape *s);
        //B1 begins here
        virtual Shape& operator+(const Shape &s);
        friend std::ostream& operator<<(std::ostream& os, const Shape &s);
        double* gettingXCoord() {return xCoord;}
        double* gettingYCoord() {return yCoord;}
        int theAmountOfCoords() {return pointCounter;}
};

#endif