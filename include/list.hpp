#ifndef LIST
#define LIST

#include "item.hpp"

class List
{
    public:
        List() {size = 0;};
        int GetSize() {return size;};
        bool Empty() {return size == 0;};

        virtual TypeItem GetItem(int pos) = 0;
        virtual void SetItem(TypeItem item, int pos) = 0;
        virtual void InsertBegin(TypeItem item) = 0;
        virtual void InsertEnd(TypeItem item) = 0;
        virtual void InsertPosition(TypeItem item, int pos) = 0;
        virtual TypeItem RemoveBegin() = 0;
        virtual TypeItem RemoveEnd() = 0;
        virtual TypeItem RemovePosition(int position) = 0;
        virtual void Print() = 0;
        virtual void Clean() = 0;

    protected:
        int size;
};

class LinkedList : public List
{
    public:
        LinkedList();
        virtual ~LinkedList();

        TypeItem GetItem(int pos);
        void SetItem(TypeItem item, int pos);
        void InsertBegin(TypeItem item);
        void InsertEnd(TypeItem item);
        void InsertPosition(TypeItem item, int pos);
        TypeItem RemoveBegin();
        TypeItem RemoveEnd();
        TypeItem RemovePosition(int pos);
        void Print();
        void Clean();

    private:
        TypeCell* first;
        TypeCell* last;      
        TypeCell* Position(int pos, bool begore);      
};

#endif