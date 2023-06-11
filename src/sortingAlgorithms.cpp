#include "sortingAlgorithms.hpp"
#include "item.hpp"
#include "types.hpp"
#include "list.hpp"


void InsertionSort(TypeItem*& item, int size) {
    TypeItem aux;
    for (int i = 1; i < size; i++) {
        aux = item[i];
        int j = i - 1;
        while (( j >= 0 ) && (aux.GetKey() < item[j].GetKey())) {
            item[j + 1] = item[j];
            j--;
    }
    item[j + 1] = aux;
  }
}

void merge(TypeItem*& points, int first, int middle, int last) {
    int leftSize = middle - first + 1;
    int rightSize = last - middle;

    TypeItem* leftPoints = new TypeItem[leftSize]();
    TypeItem* rightPoints = new TypeItem[rightSize]();

    int leftIterator;
    int rightIterator;
    int pointsIterator;

    for(leftIterator = 0; leftIterator < leftSize; leftIterator++) {
        leftPoints[leftIterator] = points[first + leftIterator];
    }
    for(rightIterator = 0; rightIterator < rightSize; rightIterator++) {
        rightPoints[rightIterator] = points[middle + rightIterator + 1];
    }

    leftIterator = 0;
    rightIterator = 0;
    pointsIterator = first;
    while (leftIterator < leftSize && rightIterator < rightSize) {
        if(leftPoints[leftIterator].GetKey() <= rightPoints[rightIterator].GetKey()) {
            points[pointsIterator] = leftPoints[leftIterator];
            leftIterator++;
        } else {
            points[pointsIterator] = rightPoints[rightIterator];
            rightIterator++;
        }
        pointsIterator++;
    }
    
    while (leftIterator < leftSize) {
        points[pointsIterator] = leftPoints[leftIterator];
        leftIterator++;
        pointsIterator++;
    }
    while (rightIterator < rightSize) {
        points[pointsIterator] = rightPoints[rightIterator];
        rightIterator++;
        pointsIterator++;
    }
    
    delete[] leftPoints;
    delete[] rightPoints;
}

void mergeSort(TypeItem* itens, int first, int last) {
    int middle;
    if(first < last) {
        middle = (first + last) / 2;
        mergeSort(itens, first, middle);
        mergeSort(itens, middle + 1, last);
        merge(itens, first, middle, last);
    }
}

void bucketSort(TypeItem* points, int numberOfPoints, int numberOfBuckets) {
    LinkedList *buckets = new LinkedList[numberOfBuckets];
    for(int i = 0; i < numberOfPoints; i++) {
        int putInBucket = static_cast<int>((points[i].GetKey() / PI) * numberOfBuckets);
        buckets[putInBucket].InsertEnd(points[i]);
    }

    int indexPoints = 0;
    for(int i = 0; i < numberOfBuckets; i++) {
        int size = buckets[i].GetSize();
        TypeItem* auxPoints = new TypeItem[size];
        int j = 0;
        while(!buckets[i].Empty()) {        
            auxPoints[j++] = buckets[i].RemoveBegin();    
        }
        mergeSort(auxPoints, 0, size-1);
        for(j = 0; j < size; j++) {
            points[indexPoints++] = auxPoints[j];
        }        
    }

    delete[] buckets;
}