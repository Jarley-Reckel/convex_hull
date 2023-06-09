#include "sortingAlgorithms.hpp"
#include "structs.hpp"
#include "types.hpp"


void InsertionSort(TypeItem* item, int size) {
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

void merge(TypeItem* points, int first, int middle, int last) {
    int leftSize = middle - first + 1;
    int rightSize = last - middle;

    TypeItem* leftPoints = new TypeItem[leftSize]();
    TypeItem* rightPoints = new TypeItem[rightSize]();

    int leftIterator;
    int rightIterator;
    int pointsIterator;

    for(leftIterator = 0; leftIterator < leftSize; leftIterator++) {
        leftPoints[leftIterator] = points[middle + leftIterator];
    }
    for(int rightIterator = 0; rightIterator < leftSize; rightIterator++) {
        leftPoints[rightIterator] = points[middle + rightIterator + 1];
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
    
    free(leftPoints);
    free(rightPoints);
}

void mergeSort(TypeItem* points, int first, int last) {
    int middle;
    if(first < last) {
        middle = (first + last) / 2;
        mergeSort(points, first, middle);
        mergeSort(points, middle + 1, last);
        merge(points, first, middle, last);
    }
}

void bucketSort(TypeItem* points, int numberOfPoints, int numberOfBuckets) {
    int pointsInBuckets = numberOfPoints / numberOfBuckets;
    TypeItem **buckets = new TypeItem*[numberOfBuckets];
    for(int i = 0; i < numberOfBuckets; i++) {
        buckets[i] = new TypeItem[pointsInBuckets];
    }

    for(int i = 0; i < numberOfPoints; i++) {
        int putInBucket = static_cast<int>(points[i].GetKey() / pointsInBuckets);
        int j = 0;
        while(putInBucket < pointsInBuckets) {
            if(buckets[putInBucket][j].GetKey() == -1) {
                buckets[putInBucket][j] = points[i];
                break;
            }
            j++;
        }        
    }

    for(int i = 0; i < numberOfBuckets; i++) {
        mergeSort(buckets[i], 0, pointsInBuckets);
    }

    int indexBucket = 0;
    for(int i = 0; i < numberOfBuckets; i++) {
        for(int j = 0; j < pointsInBuckets; j++) {
            if(buckets[i][j].GetKey() == -1) {
                break;
            }
            points[indexBucket] = buckets[i][j];
            indexBucket++;
        }
    }

    for(int i = 0; i < numberOfBuckets; i++) {
        delete[] buckets[i];
    }
    delete[] buckets;
}