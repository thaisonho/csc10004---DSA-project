#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <cstddef>
#include <algorithm>

static void __countingSort(int* arr, std::size_t n, int exp);
static void __countingSort(int* arr, std::size_t n, int exp, unsigned int& cnt);
void radixSort(int* arr, std::size_t n);
void radixSort(int* arr, std::size_t n, unsigned int& cnt);

#endif //RADIX_SORT_H