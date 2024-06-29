#include "BubbleSort.h"

void bubbleSort(int* arr, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
    }
}

void bubbleSort(int* arr, int n, long long& count_compare)
{
    for (int i = 0; ++count_compare && i < n; i++) {
        for (int j = 0; ++count_compare && j < n - i - 1; j++) {
            count_compare++;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSort_optimized(int* arr, int n)
{
    bool swapped;

    for (int i = 0;i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Nếu không có phần tử nào bị hoán đổi, mảng đã được sắp xếp
        if (!swapped)
            break;
    }
}

void bubbleSort_optimized(int* arr, int n, long long& count_compare)
{
    bool swapped;

    for (int i = 0; ++count_compare && i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; ++count_compare && j < n - i - 1; ++j) {
            if (++count_compare && arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Nếu không có phần tử nào bị hoán đổi, mảng đã được sắp xếp
        if (++count_compare && !swapped)
            break;
    }
}
