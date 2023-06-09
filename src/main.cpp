#include "types.hpp"
#include "mainFunctions.hpp"
#include "convexHullAlgorithms.hpp"

#include <iostream>
#include <fstream>


int main(int argc, char **argv) {

    if(checkPassArgument(argc) == false)
        return 0;

    std::string fileName(argv[1]);
    Point* points;
    int numberOfPoints;
    try{
        points = pickPointsInFile(fileName, numberOfPoints);
    } catch(unopened_file& error) {
        std::cout << error.what() <<std::endl;
        return 1;        
    }    

    ConvexHull grahamInsertion = grahamScan(points, numberOfPoints, "insertionSort");
    ConvexHull grahamMerge = grahamScan(points, numberOfPoints, "mergeSort");
    ConvexHull grahamBucket = grahamScan(points, numberOfPoints, "bucketSort");

    return 0;
}