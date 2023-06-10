#ifndef TYPES
#define TYPES

#include <cmath>

#define PI 3.14159265

class Point {
    
    public:
        Point();
        Point(int x, int y);

        int GetX();
        int GetY();
        float GetRadius();
        float GetThetaRadians();
        float GetThetaDegree();

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

        Point GetPoint_1();
        Point GetPoint_2();
        float GetLength();
        float GetAngle();

    private:
        Point Point_1;
        Point Point_2;
    
    friend class ConvexHull;
};



#endif