#include "types.hpp"
#include "mainFunctions.hpp"
#include "convexHullAlgorithms.hpp"

#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>


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

    ConvexHull grahamInsertion;
    ConvexHull grahamMerge;
    ConvexHull grahamBucket;

    clock_t beginInsertion;
    clock_t endInsertion;
    clock_t beginMerge;
    clock_t endMerge;
    clock_t beginBucket;
    clock_t endBucket;

    try{
        beginInsertion = clock();
        grahamInsertion = grahamScan(points, numberOfPoints, "insertionSort");
        endInsertion = clock();

        beginMerge = clock();
        grahamMerge = grahamScan(points, numberOfPoints, "mergeSort");
        endMerge = clock();

        beginBucket = clock();
        grahamBucket = grahamScan(points, numberOfPoints, "bucketSort");
        endBucket = clock();
    } catch (insuficient_points& error){
        std::cout << error.what() << std::endl;
    }

    grahamInsertion.Print();

    std::cout << std::fixed << std::setprecision(3) << std::endl;
    std::cout << std::endl;
    std::cout << "GRAHAM+MERGESORT: " << endMerge - beginMerge << "s" << std::endl;
    std::cout << "GRAHAM+InsertionSort: " << endInsertion - beginInsertion << "s" <<  std::endl;
    std::cout << "GRAHAM+Linear: " << endBucket - beginBucket << "s" << std::endl;

    return 0;
}