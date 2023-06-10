#include "item.hpp"
#include <iostream>


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

TypeKey TypeItem::GetKey() {
    return key;
}

Point TypeItem::GetContent() {
    return content;
}

void TypeItem::Print() {
    std::cout << content.GetX() << ' ' << content.GetY() << std::endl;
}