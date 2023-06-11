#ifndef CONVEXHULL
#define CONVEXHULL

#include "stack.hpp"
#include "types.hpp"

class ConvexHull {
    public:
        ConvexHull();
        ConvexHull(LinkedStack stackPoints);

        int GetNumberOfPoints();
        Point* GetPoints();
        Straight* GetStraight();
        void Print();

    private:
        int numberOfPoints;
        Point* points;
        Straight* straights;
};

#endif