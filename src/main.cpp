#include "types.hpp"
#include "mainFunctions.hpp"

#include <iostream>
#include <fstream>


int main(int argc, char **argv) {
    checkPassArgument(argc);
    std::string fileName(argv[1]);
    std::ifstream inputFile = openFile(fileName);
    Point* points = definePoints(inputFile);



    return 0;
}