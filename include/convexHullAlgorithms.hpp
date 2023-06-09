#ifndef CONVEXHULLALGORITHMS
#define CONVEXHULLALGORITHMS

#include "types.hpp"
#include <iostream>


ConvexHull grahamScan(Point* points, int size, std::string sortingAlgorithm);

#endif