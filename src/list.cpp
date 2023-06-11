#include "list.hpp"
#include "item.hpp"
#include <iostream>

LinkedList::LinkedList() : List()
{
    first = new TypeCell();
    last = first;
}

LinkedList::~LinkedList()
{
    Clean();
    delete first;
}

TypeCell *LinkedList::Position(int pos, bool before = false)
{
    TypeCell *p;
    int i;

    if ((pos > size) || (pos <= 0))
        throw "ERRO: Invalid Position!";

    p = first;
    for (i = 1; i < pos; i++)
        p = p->GetNext();

    if (!before)
        p = p->GetNext();

    return p;
}

TypeItem LinkedList::GetItem(int pos)
{
    TypeCell *p;

    p = Position(pos);
    return p->GetItem();
}

void LinkedList::SetItem(TypeItem item, int pos)
{
    TypeCell *p;

    p = Position(pos);
    p->SetItem(item);
}

void LinkedList::InsertBegin(TypeItem item)
{
    TypeCell *cell;
    cell = new TypeCell();
    cell->SetItem(item);
    cell->SetNext(first->GetNext());
    first->SetNext(cell);
    size++;

    if (cell->GetNext() == nullptr)
        last = cell;
}

void LinkedList::InsertEnd(TypeItem item)
{
    TypeCell *cell = new TypeCell();
    cell->SetItem(item);
    last->SetNext(cell);
    last = cell;
    size++;
}

void LinkedList::InsertPosition(TypeItem item, int pos)
{
    TypeCell *p, *cell;
    p = Position(pos, true);

    cell = new TypeCell();
    cell->SetItem(item);
    cell->SetNext(p->GetNext());
    p->SetNext(cell);
    size++;

    if (cell->GetNext() == nullptr)
        last = cell;
}

TypeItem LinkedList::RemoveBegin()
{
    TypeItem aux;
    TypeCell *p;

    if (size == 0)
        throw "ERRO: Empty list!";

    p = first->GetNext();
    first->SetNext(p->GetNext());
    size--;
    if (first->GetNext() == nullptr)
        last = first;
    aux = p->GetItem();
    delete p;

    return aux;
}

TypeItem LinkedList::RemoveEnd()
{
    TypeItem aux;
    TypeCell *p;

    if (size == 0)
        throw "ERRO: Empty list!";

    p = first;
    for (int i = 1; i < size; i++)
        p = p->GetNext();

    p->SetNext(nullptr);
    size--;
    aux = last->GetItem();
    delete last;
    last = p;

    return aux;
}

TypeItem LinkedList::RemovePosition(int pos)
{
    TypeItem aux;
    TypeCell *p, *q;

    if (size == 0)
        throw "ERRO: Empty List!";

    p = Position(pos, true);
    q = p->GetNext();
    p->SetNext(q->GetNext());
    size--;
    aux = q->GetItem();
    delete q;
    if (p->GetNext() == nullptr)
        last = p;
    return aux;
}

void LinkedList::Print()
{
    TypeCell *p;

    p = first->GetNext();
    while (p != nullptr)
    {
        p->GetItem().Print();
        p = p->GetNext();
    }

    std::cout << std::endl;
}

void LinkedList::Clean()
{
    TypeCell *p;

    p = first->GetNext();
    while (p != nullptr)
    {
        first->SetNext(p->GetNext());
        delete p;
        p = first->GetNext();
    }
    last = first;
    size = 0;
}