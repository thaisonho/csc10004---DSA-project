#include "shaker_sort.h"

void shakerSort(int* arr, std::size_t n)
{
    int leftPtr = 0, rightPtr = n - 1;
    bool swapped;

    while (!swapped) {
        swapped = false;
        for (int i = leftPtr; i < rightPtr; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
        swapped = false;

        --rightPtr;

        for (int i = rightPtr; i > leftPtr; --i) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                swapped = false;
            }
        }

        ++rightPtr;
    }
}

void shakerSort(int* arr, std::size_t n, long long& cnt)
{
    cnt = 0;
    int leftPtr = 0, rightPtr = n - 1;
    bool swapped;

    while (++cnt && !swapped) {
        swapped = false;
        for (int i = leftPtr; ++cnt && i < rightPtr; ++i) {
            if (++cnt && arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (++cnt && !swapped) break;
        swapped = false;

        --rightPtr;

        for (int i = rightPtr; ++cnt && i > leftPtr; --i) {
            if (++cnt && arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                swapped = false;
            }
        }

        ++rightPtr;
    }
}
