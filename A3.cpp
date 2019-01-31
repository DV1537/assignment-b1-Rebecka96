#include <iostream>
#include <string>
#include <fstream>
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"
#include "sstream"

int main(int argc, const char *argv[])
{
    int size = 0;
    int secondSize = 0;
    int sum = 0;
    int secondSum = 0;
    int nrCounter = 0;
    int secondNrCounter = 0;
    int arraySize = 0;
    double average = 0;
    double *array = new double[1]; //börjar med en plats och ökar med platser i while-loopen
    double *xCoord = nullptr;
    double *yCoord = nullptr;
    double *arraySecond = new double[1];
    double *secondXcoord = nullptr;
    double *secondYcoord = nullptr;

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
        std::stringstream s(sentence);
        
        while(s >> array[nrCounter]) //spara myFile-innehållet i arrayen
        {
            sum += array[nrCounter];

            nrCounter++;

            arraySize += 2;

            double *secondArray = new double[arraySize];
                    
            for(int i = 0; i < nrCounter; i++)
                secondArray[i] = array[i];

            delete[] array;
            array = secondArray; //array pekar på secondArray
            secondArray = nullptr;
        }
        //A3 begin here
        std::string secondSentence;
        std::getline(myFile, secondSentence);
        std::stringstream ss(secondSentence);

        while(ss >> arraySecond[secondNrCounter])
        {
            secondSum += arraySecond[secondNrCounter];

            secondNrCounter++;

            arraySize += 2;

            double *thirdArray = new double[arraySize];
                    
            for(int i = 0; i < secondNrCounter; i++)
                thirdArray[i] = arraySecond[i];

            delete[] arraySecond;
            arraySecond = thirdArray; //array pekar på secondArray
            thirdArray = nullptr;   
        }

        size = nrCounter / 2;
        
        xCoord = new double[size];
        yCoord = new double[size];
        int xSize = 0;
        int ySize = 0;

        for(int i = 0; i < nrCounter; i++) //sätter dit x- och y-koordinater i varsinn array
        {
            if(i % 2 == 0)
            {
                xCoord[xSize] = array[i];
                xSize++;
            }    
            else
            {
                yCoord[ySize] = array[i];
                ySize++;  
            }   
        }

        secondSize = secondNrCounter / 2;
        
        secondXcoord = new double[secondSize];
        secondYcoord = new double[secondSize];
        int secondXSize = 0;
        int secondYSize = 0;

        for(int i = 0; i < secondNrCounter; i++) //sätter dit x- och y-koordinater i varsinn array
        {
            if(i % 2 == 0)
            {
                secondXcoord[secondXSize] = arraySecond[i];
                secondXSize++;
            }    
            else
            {
                secondYcoord[secondYSize] = arraySecond[i];
                secondYSize++;  
            }   
        }
    }
    //objekt
    /*if(nrCounter == 2) //This is not needed in the A3 assignment, but i keep it in, i just comment it out
    {
        Point pointShape(xCoord, yCoord, nrCounter);
        std::cout << "The area is: " << pointShape.area() << '\n';
    }
    if(nrCounter == 4)
    {
        Line lineShape(xCoord, yCoord, nrCounter);
        std::cout << "The area is: " << lineShape.area() << '\n';
    }
    if(nrCounter == 6)
    {
        Triangle triangleShape(xCoord, yCoord, nrCounter);
        std::cout << "The area is: " << triangleShape.area() << '\n';
    }
    if(nrCounter > 6) {}*/
    Polygon polygonShape(xCoord, yCoord, nrCounter);
    Polygon polygonShapeSecond(secondXcoord, secondYcoord, secondNrCounter);
    Polygon polygonFusion = polygonShape + polygonShapeSecond;
    std::cout << "The area is: " << polygonFusion.area() << '\n';
    
    delete[] xCoord, yCoord, secondXcoord, secondYcoord; 
    xCoord, yCoord, secondXcoord, secondYcoord = nullptr;

    system ("PAUSE");
    
    return 0;
}

