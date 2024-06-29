#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <cstddef>
#include <algorithm>

static void __countingSort(int* arr, std::size_t n, int exp);
static void __countingSort(int* arr, std::size_t n, int exp, long long& cnt);
void radixSort(int* arr, std::size_t n);
void radixSort(int* arr, std::size_t n, long long& cnt);

#endif //RADIX_SORT_H
