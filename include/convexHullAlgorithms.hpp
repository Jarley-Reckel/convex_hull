#ifndef CONVEXHULLALGORITHMS
#define CONVEXHULLALGORITHMS

#include "types.hpp"
#include "convexHull.hpp"
#include <iostream>

class insuficient_points : public std::exception {

    public:
        virtual const char* what() const throw() { 
            return "Erro: Insuficient points.";
        }
};

ConvexHull grahamScan(Point* points, int size, std::string sortingAlgorithm);

#endif