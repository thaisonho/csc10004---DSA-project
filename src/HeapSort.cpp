#include "HeapSort.h"

void Heapify(int a[], int left, int right) // right = n - 1
{
    int i = left;
    int j = left * 2 + 1;
    int x = a[i];
    while (j <= right)
    {
        if (j < right)
            if (a[j] < a[j + 1])
                j++;
        if (x >= a[j])
            break;
        a[i] = a[j];
        i = j;
        j = 2 * i + 1;
    }
    a[i] = x;
}

void HeapSort(int a[], int n)
{
    for (int i = n / 2; i >= 0; i--)
        Heapify(a, i, n - 1);
    for (int i = n - 1; i > 0; i--)
    {
        std::swap(a[0], a[i]);
        Heapify(a, 0, i - 1);
    }
}

void HeapifyOptimize(int a[], int n, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    int largest = index;

    if (a[largest] < a[left] && left < n)
        largest = left;

    if (a[largest] < a[right] && right < n)
        largest = right;

    if (largest != index)
    {
        std::swap(a[index], a[largest]);

        HeapifyOptimize(a, n, largest);
    }
}

void HeapSortOptimize(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        HeapifyOptimize(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        std::swap(a[0], a[i]);

        HeapifyOptimize(a, i, 0);
    }
}

void Heapify(int a[], int left, int right, long long& count_compare)
{
    int i = left;
    int j = left * 2 + 1;
    int x = a[i];
    while (++count_compare && j <= right)
    {
        if (++count_compare && j < right)
            if (++count_compare && a[j] < a[j + 1])
                j++;
        if (++count_compare && x >= a[j])
            break;
        a[i] = a[j];
        i = j;
        j = 2 * i + 1;
    }
    a[i] = x;
}

void HeapSort(int a[], int n, long long& count_compare)
{
    for (int i = n / 2; ++count_compare && i >= 0; i--)
        Heapify(a, i, n - 1, count_compare);
    for (int i = n - 1; ++count_compare && i > 0; i--)
    {
        std::swap(a[0], a[i]);
        Heapify(a, 0, i - 1, count_compare);
    }
}

void HeapifyOptimize(int a[], int n, int index, long long& count_compare)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    int largest = index;

    if (++count_compare && a[largest] < a[left] && ++count_compare && left < n)
        largest = left;

    if (++count_compare && a[largest] < a[right] && ++count_compare && right < n)
        largest = right;

    if (++count_compare && largest != index)
    {
        std::swap(a[index], a[largest]);

        HeapifyOptimize(a, n, largest, count_compare);
    }
}

void HeapSortOptimize(int a[], int n, long long& count_compare)
{
    for (int i = n / 2 - 1; ++count_compare && i >= 0; i--)
        HeapifyOptimize(a, n, i, count_compare);

    for (int i = n - 1; ++count_compare && i > 0; i--)
    {
        std::swap(a[0], a[i]);

        HeapifyOptimize(a, i, 0, count_compare);
    }
}


