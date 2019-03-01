#include <iostream>
#include <sstream>
#include "Figure.h"
#include "ExtraFunction.h"

Figure::Figure()
{
    figure = nullptr;
    nrCounter = 0;
}

Figure::Figure(Shape** shape, int nrCounter)
{
    this -> figure = new Shape*[nrCounter];

    for(int i = 0; i < nrCounter; i++)
        figure[i] = shape[i];

    this -> nrCounter = nrCounter;
}

void Figure::addShape(Shape *s)
{
    nrCounter += 1;

    Shape **temporary = new Shape*[nrCounter];

    for(int i = 0; i < nrCounter; i++)
        temporary[i] = figure[i];

    temporary[nrCounter - 1] = s;
    delete [] figure;
    figure = temporary;
}

Line Figure::getBoundingBox()
{
    double topLeftX = 0, topLeftY = 0;
    double bottomRightX = 0, bottomRightY = 0;

    for(int i = 0; i < nrCounter; i++)
    {
        double *temporaryX = figure[i] -> gettingXCoord();
        double *temporaryY = figure[i] -> gettingYCoord();
        int nrOfCoords = figure[i] -> theAmountOfCoords();

        if(i == 0)
        {
            topLeftX = temporaryX[0];
            topLeftY = temporaryY[0];
            bottomRightX = temporaryX[0];
            bottomRightY = temporaryY[0];
        }

        for(int j = 0; j < nrOfCoords; j++)
        {
            if(temporaryX[j] < topLeftX)
                topLeftX = temporaryX[j];
            
            else if(temporaryX[j] > bottomRightX)
                bottomRightX = temporaryX[j];

            if(temporaryY[j] > topLeftY)
                topLeftY = temporaryY[j];

            else if(temporaryY[j] < bottomRightY)
                bottomRightY = temporaryY[j];
        }
    }
    double xCoord[2];
    double yCoord[2];
    xCoord[0] = topLeftX;
    xCoord[1] = bottomRightX;
    yCoord[0] = topLeftY;
    yCoord[1] = bottomRightY;

    Line line(xCoord, yCoord, 2);

    return line;
}

Shape** Figure::getClosest(Shape* location, int n)
{
    if(n > nrCounter)
        return figure;
    
    double *distances = new double[nrCounter];

    for(int i = 0; i < nrCounter; i++)
        distances[i] = figure[i] -> distance(location);

    int startingPoint = 0;
    int endingPoint = (nrCounter - 1);

    quickSort(distances, startingPoint, endingPoint);

    Shape **closestShapes = new Shape*[n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < nrCounter; j++)
        {
            if(distances[i] == figure[j] -> distance(location))
                closestShapes[i] = figure[j];
        }
    }
    delete [] distances;
    distances = nullptr;

    return closestShapes;
}

Figure::~Figure()
{
    for(int i = 0; i < nrCounter; i++)
    {
        if(figure[i])
            figure[i] = nullptr;

        delete [] figure;
    }
}
