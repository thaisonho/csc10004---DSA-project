#include "insertion_sort.h"

// Implementation without counting comparisions
void InsertionSort(int* a, int n){
    for (int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        while (a[j] > key && j >= 0) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void BinaryInsertionSort(int* a, int n){
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int start = 0;
        int end = i - 1;

        while (start <= end) {
            int mid = (start + end) >> 1;
            if (a[mid] < key) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        for (int j = i - 1; j >= start; --j) {
            a[j + 1] = a[j];
        }
        a[start] = key;
    }
}

// Implementation with counting comparisions
void InsertionSort(int* a, int n, long long& comparison){
    for (int i = 1; ++comparison && i < n; i++){
        int key = a[i];
        int j = i - 1;
        while (++comparison && a[j] > key && ++comparison && j >= 0){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void BinaryInsertionSort(int* a, int n, long long& comparison){
    for (int i = 1; ++comparison && i < n; i++)
    {
        int key = a[i];
        int start = 0;
        int end = i - 1;
        while (++comparison && start <= end){
            int mid = (start + end) >> 1;
            if (++comparison && a[mid] < key){
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        for (int j = i - 1; ++comparison && j >= start; j--){
            a[j + 1] = a[j];
        }
        a[start] = key;
    }
}
