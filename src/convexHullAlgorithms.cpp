#include "convexHullAlgorithms.hpp"
#include "sortingAlgorithms.hpp"
#include "types.hpp"
#include "structs.hpp"
#include <iostream>

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

    TypeItem* itens = new TypeItem[size - 1]();
    int itemPosition = 0;
    for(int i = 0; i < size; i++) {
        if(i == pivotPosition) {
            continue;
        }
        int x = points[i].GetX() - pivot.GetContent().GetX();
        int y = points[i].GetY() - pivot.GetContent().GetY();
        float angle = atan(y/x);
        itens[itemPosition] = TypeItem(points[i], angle);
        itemPosition++;
    }

    if(sortingAlgorithm == "insertionSort") {
        InsertionSort(itens, size - 1);
    } else if(sortingAlgorithm == "mergeSort") {
        mergeSort(itens, 0, size - 1);
    } else if(sortingAlgorithm == "bucketSort") {
        bucketSort(itens, size - 1, 4);
    }

    LinkedStack ConvexHullPoints;
    ConvexHullPoints.Push(pivot);
    ConvexHullPoints.Push(itens[0]);
    for(int i = 0; i < size - 1; i++){
        //TODO
    }


    delete(itens);
}