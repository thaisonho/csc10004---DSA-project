#include "QuickSort.h"

int partition(int* arr, int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int* arr, int start, int end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}

int partition(int* arr, int start, int end, long long& count_compare)
{

    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1; ++count_compare && i <= end; i++) {
        count_compare++;
        if (arr[i] <= pivot) {
            count++;
        }
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (count_compare += 2, i < pivotIndex && j > pivotIndex) {
        while (++count_compare && arr[i] <= pivot) {
            i++;
        }

        while (++count_compare && arr[j] > pivot) {
            j--;
        }

        if (count_compare += 2, i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int* arr, int start, int end, long long& count_compare)
{
    // base case
    if (++count_compare && start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end, count_compare);

    // Sorting the left part
    quickSort(arr, start, p - 1, count_compare);

    // Sorting the right part
    quickSort(arr, p + 1, end, count_compare);
}

// GPT
int medianOfThree(int* arr, int left, int right)
{
    int mid = left + (right - left) / 2;

    if (arr[left] > arr[mid])
        std::swap(arr[left], arr[mid]);
    if (arr[left] > arr[right])
        std::swap(arr[left], arr[right]);
    if (arr[mid] > arr[right])
        std::swap(arr[mid], arr[right]);

    // Sau khi sắp xếp, arr[mid] là giá trị median
    return mid;
}

// Hàm phân đoạn mảng
int partition_optimized(int* arr, int left, int right)
{
    int pivotIndex = medianOfThree(arr, left, right);
    int pivotValue = arr[pivotIndex];
    std::swap(arr[pivotIndex], arr[right]); // Di chuyển pivot tới cuối mảng
    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            std::swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    std::swap(arr[storeIndex], arr[right]); // Di chuyển pivot về vị trí đúng
    return storeIndex;
}

// Hàm QuickSort chính
void quickSort_optimized(int* arr, int left, int right)
{
    if (left < right) {
        int pivotIndex = partition_optimized(arr, left, right);
        quickSort_optimized(arr, left, pivotIndex - 1);
        quickSort_optimized(arr, pivotIndex + 1, right);
    }
}

int medianOfThree(int* arr, int left, int right, long long& count_compare)
{
    int mid = left + (right - left) / 2;

    if (++count_compare && arr[left] > arr[mid])
        std::swap(arr[left], arr[mid]);
    if (++count_compare && arr[left] > arr[right])
        std::swap(arr[left], arr[right]);
    if (++count_compare && arr[mid] > arr[right])
        std::swap(arr[mid], arr[right]);

    // Sau khi sắp xếp, arr[mid] là giá trị median
    return mid;
}

// Hàm phân đoạn mảng
int partition_optimized(int* arr, int left, int right, long long& count_compare)
{
    int pivotIndex = medianOfThree(arr, left, right);
    int pivotValue = arr[pivotIndex];
    std::swap(arr[pivotIndex], arr[right]); // Di chuyển pivot tới cuối mảng
    int storeIndex = left;

    for (int i = left; ++count_compare && i < right; i++) {
        if (++count_compare && arr[i] < pivotValue) {
            std::swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    std::swap(arr[storeIndex], arr[right]); // Di chuyển pivot về vị trí đúng
    return storeIndex;
}

void quickSort_optimized(int* arr, int left, int right, long long& count_compare)
{
    if (++count_compare && left < right) {
        int pivotIndex = partition_optimized(arr, left, right);
        quickSort_optimized(arr, left, pivotIndex - 1);
        quickSort_optimized(arr, pivotIndex + 1, right);
    }
}
