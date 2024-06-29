#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <utility>

int partition(int* arr, int start, int end);
void quickSort(int* arr, int start, int end);
int partition(int* arr, int start, int end, long long& count_compare);
void quickSort(int* arr, int start, int end, long long& count_compare);

#endif
