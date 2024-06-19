#include "../include/algorithms/radix_sort.h"

void __countingSort(int* arr, std::size_t n, int exp)
{
    int* output = (int*)std::calloc(n, sizeof(int));
    int count[10] = { 0 };

    for (std::size_t i = 0; i < n; ++i) {
        ++count[(arr[i] / exp) % 10];
    }

    for (std::size_t i = 1; i < n; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (std::size_t i = 0; i < n; ++i) {
        arr[i] = output[i];
    }

    free(output);
}

void __countingSort(int* arr, std::size_t n, int exp, unsigned int& cnt)
{
    cnt = 0;
    int* output = (int*)std::calloc(n, sizeof(int));
    int count[10] = { 0 };

    for (std::size_t i = 0; ++cnt && i < n; ++i) {
        int digit = (arr[i] / exp) % 10;
        ++count[digit];
    }

    for (std::size_t i = 1; ++cnt && i < n; ++i) {
        count[i] += count[i - 1];
        ++cnt;
    }

    for (int i = n - 1; ++cnt && i >= 0; --i) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        --count[digit];
    }

    for (std::size_t i = 0; ++cnt && i < n; ++i) {
        arr[i] = output[i];
    }

    free(output);
}

void radixSort(int* arr, std::size_t n)
{
    int max = *std::max_element(arr, arr + n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        __countingSort(arr, n, exp);
    }
}

void radixSort(int* arr, std::size_t n, unsigned int& cnt)
{
    cnt = 0;
    int max = *std::max_element(arr, arr + n);
    unsigned int tmpCnt;
    for (int exp = 1; ++cnt && max / exp > 0; exp *= 10) {
        __countingSort(arr, n, exp, tmpCnt);
        cnt += tmpCnt;
    }
}