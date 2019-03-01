#include <iostream>
#include "Shape.h"
#include "Polygon.h"
#include "Triangle.h"
#include "Line.h"
#include "Point.h"

Shape* getShape(int nrCounter, double *xCoord, double *yCoord);

Shape* collectShapes(std::string sentence);

void swap(double* a, double* b);

int partition(double array[], int high, int low);

void quickSort(double array[], int high, int low);
