#ifndef STACK
#define STACK

#include "item.hpp"

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

class Stack
{
    public:
        Stack() {size = 0;};
        int GetSize() {return size;};
        bool EmptyStack() {return size == 0;};

        virtual void Push(TypeItem item) = 0;
        virtual TypeItem Pop() = 0;
        virtual void Clean() = 0;
        virtual TypeItem GetTop() = 0;
    
    protected:
        int size;
};

class LinkedStack : public Stack
{
    public:
        LinkedStack();
        virtual ~LinkedStack();

        void Push(TypeItem item);
        TypeItem Pop();
        void Clean();
        TypeItem GetTop();

    private:
        TypeCell* top;
};

#endif