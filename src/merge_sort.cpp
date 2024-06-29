#include "merge_sort.h"

// Implementation without counting comparisions
void Merge(int* arr, int left, int mid, int right) {
    int* temp = new int[right - left + 1];
    int i = left; // flag as the beginning of the first part
    int j = mid + 1; // flag as the beginning of the second part
    int k_sz = 0; // size of the temp

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k_sz++] = arr[i++];
        } else {
            temp[k_sz++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k_sz++] = arr[i++];
    }

    while (j <= right) {
        temp[k_sz++] = arr[j++];
    }

    for (int i = 0; i < k_sz; ++i) {
        arr[left + i] = temp[i];
    }

    delete[] temp;
}

void MergeSort(int* arr, int left, int right) {
    if (left >= right) return;

    int mid = left + ((right - left) >> 1);
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

void MergeSort(int* arr, int n) {
    if (n > 0) {
        MergeSort(arr, 0, n - 1);
    }
}


// Implementation with counting comparisions
void Merge(int* arr, int left, int mid, int right, long long& comparisons) {
    int* temp = new int[right - left + 1];
    int i = left;
    int j = mid + 1;
    int k_sz = 0;

    while (++comparisons && i <= mid && ++comparisons && j <= right) {
        if (++comparisons && arr[i] < arr[j]) {
            temp[k_sz++] = arr[i++];
        } else {
            temp[k_sz++] = arr[j++];
        }
    }

    while (++comparisons && i <= mid) {
        temp[k_sz++] = arr[i++];
    }

    while (++comparisons && j <= right) {
        temp[k_sz++] = arr[j++];
    }

    for (int i = 0; ++comparisons && i < k_sz; ++i) {
        arr[left + i] = temp[i];
    }

    delete[] temp;
}

void MergeSort(int* arr, int left, int right, long long& comparisons) {
    if (++comparisons && left >= right) return;

    int mid = left + ((right - left) >> 1);
    MergeSort(arr, left, mid, comparisons);
    MergeSort(arr, mid + 1, right, comparisons);
    Merge(arr, left, mid, right, comparisons);
}

void MergeSort(int* arr, int n, long long& comparisons) {
    if (n > 0) {
        MergeSort(arr, 0, n - 1, comparisons);
    }
}
