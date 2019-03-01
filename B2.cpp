#include <iostream>
#include <string>
#include <fstream>
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"
#include "sstream"
#include "ExtraFunction.h"
#include "Figure.h"
#include "Shape.h"

int main(int argc, const char *argv[])
{
    int sum = 0;
    int nrCounter = 0;
    int arraySize = 0;
    //double *xCoord = nullptr;
    //double *yCoord = nullptr;
    Shape** shapes = new Shape*[arraySize];
    int seriesOfCoords = 0;

    std::ifstream myFile;

    myFile.open(argv[1]); 

    if(!myFile.is_open()) //om filen inte går att öppna, visa fel-meddelande och avsluta programmet
    {
        std::cout << "ERROR! The file could not open!" << '\n';
        system ("PAUSE");
    }else
    {
        std::string sentence;
        std::getline(myFile, sentence);
        
        
        while(!(sentence.empty())) //spara myFile-innehållet i arrayen, s >> array[nrCounter]
        {
            if(nrCounter == arraySize)
            {
                Shape** temporary = new Shape*[arraySize * 2];

                for(int i = 0; i < arraySize; i++)
                    temporary[i] = shapes[i];
                
                arraySize *= 2;
                delete [] shapes;
                shapes = temporary;
                temporary = nullptr;
            }
            shapes[seriesOfCoords] = collectShapes(sentence);
            sentence.clear();
            std::getline(myFile, sentence);
            seriesOfCoords++;
        }
        myFile.close();
    }

    Figure figure(shapes, seriesOfCoords);

     Shape **closestShapes = figure.getClosest(shapes[0], 3);

    for(int i = 0; i < 3; i++)
        std::cout << *closestShapes[i];

    std::getchar();

    system ("PAUSE");
    
    return 0;
}


                /*sum += array[nrCounter];
                nrCounter++;

                arraySize += 2;

                double *secondArray = new double[arraySize];
                                    
                delete[] array;
                array = secondArray; //array pekar på secondArray
                secondArray = nullptr;*/
