#include "../include/algorithms/shaker_sort.h"

void shakerSort(int* arr, std::size_t n)
{
    int leftPtr = 0, rightPtr = n - 1;
    bool swapped;

    while(!swapped) {
        swapped = false;
        for(int i = leftPtr; i < rightPtr; ++i) {
            if(arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true; 
            }
        }

        if(!swapped) break;
        swapped = false;

        --rightPtr;

        for(int i = rightPtr; i > leftPtr; --i) {
            if(arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                swapped = false;    
            }
        }

        ++rightPtr;
    }
}
