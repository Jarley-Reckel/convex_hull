#include "convexHull.hpp"
#include "stack.hpp"

ConvexHull::ConvexHull() {
    numberOfPoints = 0;
    points = new Point();
    straights = new Straight();
}

ConvexHull::ConvexHull(LinkedStack stackPoints) {
    numberOfPoints = stackPoints.GetSize();
    Point* convexHullPoints = new Point[numberOfPoints];
    Straight* convexHullStraight = new Straight[numberOfPoints];
    Point point_1;
    Point point_2;
    for(int i = 0; i < numberOfPoints; i++) {
        point_1 = stackPoints.Pop().GetContent();
        convexHullPoints[i] = point_1;

        if(i == numberOfPoints - 1) {
            point_2 = convexHullPoints[0];
        } else {
            point_2 = stackPoints.GetTop().GetContent();
        }

        Straight aux = Straight(point_1, point_2);
        convexHullStraight[i] = aux;
    }
    points = convexHullPoints;
    straights = convexHullStraight;
}

int ConvexHull::GetNumberOfPoints() {
    return numberOfPoints;
}

Point* ConvexHull::GetPoints() {
    return points;
}

Straight* ConvexHull::GetStraight() {
    return straights;
}