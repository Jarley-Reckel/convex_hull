#include "types.hpp"
#include "mainFunctions.hpp"

#include <iostream>
#include <fstream>


int main(int argc, char **argv) {

    if(checkPassArgument(argc) == false)
        return 0;

    std::string fileName(argv[1]);
    Point* points;
    try{
        points = pickPointsInFile(fileName);
    } catch(unopened_file& error) {
        std::cout << error.what() <<std::endl;
        return 1;        
    }

    return 0;
}