#ifndef ITEM
#define ITEM

#include "types.hpp"

typedef float TypeKey;

class TypeItem {
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

#endif