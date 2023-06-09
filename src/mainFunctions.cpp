#include "mainFunctions.hpp"
#include "types.hpp"
#include <iostream>
#include <fstream>
#include <string>

bool checkPassArgument(int argc) {
    if(argc < 2) 
        return false;
    else
        return true;
}

int defineNumberOfLines(std::ifstream& inputFile) {
    int lines = 0;
    while(!inputFile.eof()) {
        lines++;
        std::string trash;
        std::getline(inputFile, trash);
    }
    return lines - 1;
}

Point stringToPoint(std::string line) {
    std::string aux = "";
    int xyCoordinates[2];
    int lineIterator = 0;
    while(true) {
        if(line[lineIterator] == ' ') {
            xyCoordinates[0] = std::stoi(aux);
            aux = "";
        } else if(line[lineIterator] == '\0') {
            xyCoordinates[1] = std::stoi(aux);
            break;
        } else {
            aux += line[lineIterator];
        }
        lineIterator++;
    }

    Point point = Point(xyCoordinates[0], xyCoordinates[1]);
    return point;
}

Point* pickPointsInFile(std::string fileName, int &numberOfPoints) {
    std::ifstream inputFile;
    inputFile.open(fileName);
    if(!inputFile.is_open())
        throw unopened_file();
    numberOfPoints = defineNumberOfLines(inputFile);
    inputFile.close();

    inputFile.open(fileName);
    if(!inputFile.is_open())
        throw unopened_file();

    Point* points = new Point[numberOfPoints]();
    for(int i = 0; i < numberOfPoints; i++) {
        std::string line;
        std::getline(inputFile, line);
        points[i] = stringToPoint(line);
    }
    inputFile.close();
    return points;
}