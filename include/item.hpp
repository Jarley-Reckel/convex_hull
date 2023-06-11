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

class TypeCell {
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