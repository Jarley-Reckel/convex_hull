#include "types.hpp"
#include<cmath>

float findNorm(int x, int y) {
    return sqrt(x*x + y*y);
}


Point::Point() {
    X = 0;
    Y = 0;
}

Point::Point(int x, int y) {
    X = x;
    Y = y;
}

int Point::getX() {
    return X;
}

int Point::getY() {
    return Y;
}

float Point::getRadius() {
    return findNorm(X,Y);
}

Straight::Straight() {
    Point_1 = Point();
    Point_2 = Point();
}

Straight::Straight(Point point_1, Point point_2) {
    Point_1 = point_1;
    Point_2 = point_2;
}

Point Straight::getPoint_1() {
    return Point_1;
}

Point Straight::getPoint_2() {
    return Point_2;
}

float Straight::getLength() {
    int xDistance = Point_2.getX() - Point_1.getX();
    int yDistance = Point_2.getY() - Point_1.getY();
    return findNorm(xDistance, yDistance);
}

