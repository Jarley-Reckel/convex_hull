#include "mainFunctions.hpp"
#include "types.hpp"
#include "structs.hpp"
#include <iostream>
#include <fstream>



void checkPassArgument(int argc) {
    if(argc < 2) 
        throw std::invalid_argument("Pass a file");
}

std::ifstream openFile(std::string fileName) {
    std::ifstream inputFile(fileName);
    if(!inputFile.is_open())
        throw unopened_file();
    return inputFile;
}

int defineNumberOfLines(std::ifstream& inputFile) {
    int lines = 0;
    while(!inputFile.eof()) {
        lines++;
        std::string trash;
        std::getline(inputFile, trash);
    }
    inputFile.seekg(0, inputFile.beg);
    return lines;
}

Point stringToPoint(std::string line) {
    std::string aux = "";
    int xyCoordinates[2];
    int lineIterator = 0;
    do{
        if(line[lineIterator] == ' ') {
            xyCoordinates[0] = stoi(aux);
            aux = "";
        } else if(line[lineIterator] == '\0') {
            xyCoordinates[1] = stoi(aux);
        } else {
            aux += line[lineIterator];
        }
        lineIterator++;
    } while(line[lineIterator] != '\0');

    Point point = Point(xyCoordinates[0], xyCoordinates[1]);
    return point;
}

Point* definePoints(std::ifstream& inputFile) {
    int lines = defineNumberOfLines(inputFile);
    Point* points = new Point[lines]();

    for(int i = 0; i < lines; i++) {
        std::string line;
        getline(inputFile, line);
        points[i] = stringToPoint(line);
    }
    return points;    
}