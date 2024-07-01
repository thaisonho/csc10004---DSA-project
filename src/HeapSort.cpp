#include "HeapSort.h"

void Heapify(int a[], int n, int index)
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

        Heapify(a, n, largest);
    }
}

void HeapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        std::swap(a[0], a[i]);

        Heapify(a, i, 0);
    }
}

void Heapify(int a[], int n, int index, long long& count_compare)
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

        Heapify(a, n, largest, count_compare);
    }
}

void HeapSort(int a[], int n, long long& count_compare)
{
    for (int i = n / 2 - 1; ++count_compare && i >= 0; i--)
        Heapify(a, n, i, count_compare);

    for (int i = n - 1; ++count_compare && i > 0; i--)
    {
        std::swap(a[0], a[i]);

        Heapify(a, i, 0, count_compare);
    }
}


