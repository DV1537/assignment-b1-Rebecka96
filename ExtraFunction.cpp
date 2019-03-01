#include <iostream>
#include "ExtraFunction.h"
#include "Shape.h"
#include <sstream>

Shape* collectShapes(std::string sentence)
{
    int size = 0;
    double number = 0;
    int nrCounter = 0;
    int arraySize = 0;
    double *shapeCoord = new double[arraySize];
    std::stringstream s(sentence);

    while(s >> number) // Extends the array if there are no places left to fill
    {
        if(nrCounter == arraySize)
        {
            double *temporary = new double[arraySize * 2];
            
            for(int i = 0; i < arraySize; i++)
                temporary[i] = shapeCoord[i];

            arraySize *= 2;
            delete [] shapeCoord;
            shapeCoord = temporary;
            temporary = nullptr;
        }
        shapeCoord[nrCounter] = number;
        nrCounter++;
    }
       size = nrCounter / 2;
        
        double *xCoord = new double[size];
        double *yCoord = new double[size];
        int xSize = 0;
        int ySize = 0;

        for(int i = 0; i < nrCounter; i++) //decides where to put the x- and y-coordinates, seperately
        {
            if(i % 2 == 0)
            {
                xCoord[xSize] = shapeCoord[i];
                xSize++;
            }    
            else
            {
                yCoord[ySize] = shapeCoord[i];
                ySize++;  
            }   
        }
        delete [] shapeCoord;
        shapeCoord = nullptr;

        Shape *shape = getShape(nrCounter, xCoord, yCoord);

        return shape;
}

Shape* getShape(int nrCounter, double *xCoord, double *yCoord) //This decides what shape the coordinates create
{
    Shape* rightShape;

    if(nrCounter == 2)
        rightShape = new Point(xCoord, yCoord, nrCounter);

    if(nrCounter == 4)
        rightShape = new Line(xCoord, yCoord, nrCounter);

    if(nrCounter == 6)
        rightShape = new Triangle(xCoord, yCoord, nrCounter);

    if(nrCounter > 6)
        rightShape = new Polygon(xCoord, yCoord, nrCounter);

    return rightShape;
}

void swap(double* a, double* b)
{
    double z = *a;
    *a = *b;
    *b = z;
}

int partition(double array[], int high, int low)
{
    double pivot = array[high];
    int i = (low - 1);

    for(int j = low; j <= (high - 1); j++)
    {
        if(array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);

    return (i + 1);
}

void quickSort(double array[], int high, int low)
{
    if(low < high)
    {
        int p = partition(array, high, low);
        quickSort(array, p - 1, low);
        quickSort(array, high, p + 1);
    }
}
