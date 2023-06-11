#include "convexHullAlgorithms.hpp"
#include "sortingAlgorithms.hpp"
#include "types.hpp"
#include "stack.hpp"
#include "item.hpp"
#include "convexHull.hpp"
#include <iostream>


float orientation(Point next, Point top, Point curent) {
    float vetorialProduct = (top.GetY() - next.GetY()) * (curent.GetX() - top.GetX()) -
                            (top.GetX() - next.GetX()) * (curent.GetY() - top.GetY());
    if(vetorialProduct == 0) {
        return 0;
    }
    return (vetorialProduct > 0)? 1:2;
}

Point nextToTop(LinkedStack& stack) {
    TypeItem aux = stack.Pop();
    Point next = stack.GetTop().GetContent();
    stack.Push(aux);
    return next;
}


ConvexHull grahamScan(Point* points, int size, std::string sortingAlgorithm) {
    TypeItem pivot = TypeItem(points[0], 0);
    int pivotPosition = 0;
    for(int i = 1; i < size; i++) {
        if(points[i].GetY() < pivot.GetContent().GetY()) {
            pivot.SetContent(points[i]);
            pivotPosition++;
        } else if(points[i].GetY() == pivot.GetContent().GetY()) {
            if(points[i].GetX() < pivot.GetContent().GetX()) {
                pivot.SetContent(points[i]);
                pivotPosition++;
            }
        }
    }

    TypeItem* itens = new TypeItem[size]();
    int itemPosition = 1;
    for(int i = 0; i < size; i++) {
        if(i == pivotPosition) {
            continue;
        }
        float x = points[i].GetX() - pivot.GetContent().GetX();
        float y = points[i].GetY() - pivot.GetContent().GetY();
        float angle;
        if(x == 0) {
            angle = PI/2;
        } else {
            angle = atan(y/x);
        }
        itens[itemPosition] = TypeItem(points[i], angle);
        itemPosition++;
    }
    itens[0] = pivot;

    if(sortingAlgorithm == "insertionSort") {
        InsertionSort(itens, size);
    } else if(sortingAlgorithm == "mergeSort") {
        mergeSort(itens, 0, size-1);
    } else if(sortingAlgorithm == "bucketSort") {
        bucketSort(itens, size, 4);
    }

    int m = 1;
    for(int i = 1; i < size; i++){
        while (i < size && orientation(pivot.GetContent(), itens[i].GetContent(), itens[i+1].GetContent()) == 0) {
            itens[i+1] = itens[i];
            i++;
        }
        itens[m] = itens[i];
        m++;        
    }
    if(m < 3) {
        throw insuficient_points();
    }

    LinkedStack ConvexHullPoints;
    ConvexHullPoints.Push(itens[0]);
    ConvexHullPoints.Push(itens[1]);
    ConvexHullPoints.Push(itens[2]);

    for(int i = 3; i <= m; i++) {
        Point top = ConvexHullPoints.GetTop().GetContent();
        Point next = nextToTop(ConvexHullPoints);
        while(ConvexHullPoints.GetSize() > 1 && orientation(next, top, itens[i].GetContent()) != 2) {
            ConvexHullPoints.Pop();
            top = ConvexHullPoints.GetTop().GetContent();
            next = nextToTop(ConvexHullPoints);
        }
        ConvexHullPoints.Push(itens[i]);
    }    

    delete(itens);

    ConvexHull convexHull = ConvexHull(ConvexHullPoints);
    return convexHull;
}