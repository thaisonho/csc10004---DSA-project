#include "SelectionSort.h"

void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_idx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
            std::swap(a[min_idx], a[i]);
    }
}

void SelectionSort(int a[], int n, long long& count_compare)
{
    for (int i = 0; ++count_compare && i < n; i++)
    {
        int min_idx = i;

        for (int j = i + 1; ++count_compare && j < n; j++)
        {
            if (++count_compare && a[j] < a[min_idx])
                min_idx = j;
        }

        if (++count_compare && min_idx != i)
            std::swap(a[min_idx], a[i]);
    }
}

void SelectionSortOptimize(int a[], int n)
{
    int m = n;

    for (int i = 0; i < m - 1; i++)
    {
        int min_idx = i;
        int max_idx = i;

        for (int j = i + 1; j < m; j++)
        {
            if (a[min_idx] > a[j])
                min_idx = j;

            if (a[max_idx] < a[j])
                max_idx = j;
        }

        std::swap(a[min_idx], a[i]); // Shifting

        if (max_idx == i)
            max_idx = min_idx;

        m--;

        std::swap(a[max_idx], a[m]);
    }
}


void SelectionSortOptimize(int a[], int n, long long& count_compare)
{
    int m = n;

    for (int i = 0; ++count_compare && i < m - 1; i++)
    {
        int min_idx = i;
        int max_idx = i;

        for (int j = i + 1; ++count_compare && j < m; j++)
        {
            if (++count_compare && a[min_idx] > a[j])
                min_idx = j;

            if (++count_compare && a[max_idx] < a[j])
                max_idx = j;
        }

        std::swap(a[min_idx], a[i]); // Shifting
        if (++count_compare && max_idx == i)
            max_idx = min_idx;

        m--;

        std::swap(a[max_idx], a[m]);
    }
}

