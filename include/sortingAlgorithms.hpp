#ifndef SORTINGALGORITHMS
#define SORTINGALGORITHMS

#include "types.hpp"

void InsertionSort(TypeItem *v, int n);

void mergeSort(TypeItem* points, int first, int last);

void bucketSort(TypeItem* points, int numberOfPoints, int buckets);

#endif