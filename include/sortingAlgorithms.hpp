#ifndef SORTINGALGORITHMS
#define SORTINGALGORITHMS

#include "item.hpp"

void InsertionSort(TypeItem*& item, int size);

void mergeSort(TypeItem* itens, int first, int last);

void bucketSort(TypeItem* points, int numberOfPoints, int buckets);

#endif