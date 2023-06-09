#include "types.hpp"
#include <cmath>
#include <iostream>

float vetorialNorm(int x, int y) {
    return sqrt(x*x + y*y);
}

int axisDistance(int begin, int end) {
    int diference = end - begin;
    return int(sqrt(diference*diference));
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
    return vetorialNorm(X,Y);
}

float Point::getThetaRadians() {
    return atan(Y/X);
}

float Point::getThetaDegree() {
    return atan(Y/X) * 180 / PI;
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
    int xDistance = axisDistance(Point_2.getX(), Point_1.getX());
    int yDistance = axisDistance(Point_2.getY(), Point_1.getY());
    return vetorialNorm(xDistance, yDistance);
}

TypeItem::TypeItem() {
    content = Point();
    key = -1;
}

TypeItem::TypeItem(Point point, float angle) {
    content = point;
    key = angle;
}

void TypeItem::SetKey(float angle) {
    key = angle;
}

void TypeItem::SetContent(Point point) {
    content = point;
}

float TypeItem::GetKey() {
    return key;
}

Point TypeItem::GetContent() {
    return content;
}

void TypeItem::Print() {
    std::cout << content.getX() << ' ' << content.getY() << std::endl;
}

TypeCell::TypeCell() {
    item.SetContent(Point());
    next = nullptr;
}

TypeItem TypeCell::GetItem() {
    return item;
}

TypeCell *TypeCell::GetNext() {
    return next;
}

void TypeCell::SetItem(TypeItem newItem) {
    item = newItem;
}

void TypeCell::SetNext(TypeCell *cell) {
    next = cell;
}