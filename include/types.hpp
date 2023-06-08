#ifndef TYPES
#define TYPES

#include <cmath>

#define PI 3.14159265

class Point {
    
    public:
        Point();
        Point(int x, int y);

        int getX();
        int getY();
        float getRadius();
        float getThetaRadians();
        float getThetaDegree();

    private:
        int X;
        int Y;

    friend class Straight;
    friend class ConvexHull;
};

class Straight {

    public:
        Straight();
        Straight(Point point_1, Point point_2);

        Point getPoint_1();
        Point getPoint_2();
        float getLength();

    private:
        Point Point_1;
        Point Point_2;
    
    friend class ConvexHull;
};

class ConvexHull {

    //TODO implemente this class when know what the needs are
};


#endif