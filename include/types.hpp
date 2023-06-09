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

class ConvexHull {

    //TODO implemente this class when know what the needs are
};


typedef float TypeKey;

class TypeItem
{
    public:
        TypeItem();
        TypeItem(Point point, float angle);
        void SetKey(float angle);
        void SetContent(Point point);
        float GetKey();
        Point GetContent();
        void Print();

    private:
        TypeKey key;
        Point content;
};

class TypeCell
{
    public:
        TypeCell();

        TypeItem GetItem();
        TypeCell* GetNext();
        void SetItem(TypeItem newItem);
        void SetNext(TypeCell *cell);

    private:
        TypeItem item;
        TypeCell *next;

    friend class LinkedStack;
};


#endif