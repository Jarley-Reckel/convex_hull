#include "stack.hpp"
#include <iostream>


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

LinkedStack::LinkedStack() : Stack()
{
    top = nullptr;
}

LinkedStack::~LinkedStack()
{
    Clean();
}

void LinkedStack::Push(TypeItem item)
{
    TypeCell *cell;
    cell = new TypeCell();
    cell->SetItem(item);
    cell->SetNext(top);
    top = cell;
    size++;
}

TypeItem LinkedStack::Pop()
{
    TypeItem aux;
    TypeCell *p;

    if (size == 0)
        throw "Empty stack!";

    aux = top->GetItem();
    p = top;
    top = top->GetNext();
    size--;

    return aux;
}

void LinkedStack::Clean()
{
    while (!EmptyStack())
        Pop();
}

TypeItem LinkedStack::GetTop() {
    TypeItem top = this->Pop();
    this->Push(top);
    return top;
}