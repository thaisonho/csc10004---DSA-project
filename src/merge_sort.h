#ifndef MERGE_SORT_HEADER
#define MERGE_SORT_HEADER

#include <cstdlib>

void Merge(int* arr, int left, int mid, int right);

void MergeSort(int* arr, int left, int right);

void MergeSort(int* arr, int n);

void Merge(int* arr, int left, int mid, int right, long long& comparisons);

void MergeSort(int* arr, int left, int right, long long& comparisons);

void MergeSort(int* arr, int n, long long& comparisons);

#endif // MERGE_SORT_HEADER
