#include "ShellSort.h"

void ShellSort(int a[], int n)
{
    const int gaps[] = { 65921, 16577, 4193, 1073, 281, 77, 23, 8, 1 };

    for (int idx = 0; idx < 9; idx++)
    {
        int gap = gaps[idx];
        for (int i = gap; i < n; i++)
        {
            int v = a[i];
            int j = i;
            while (j >= gap && a[j - gap] > v)
            {
                a[j] = a[j - gap];
                j -= gap;
            }

            a[j] = v;
        }
    }
}


void ShellSort(int a[], int n, long long& count_compare)
{
    const int gaps[] = { 65921, 16577, 4193, 1073, 281, 77, 23, 8, 1 };

    for (int idx = 0; ++count_compare && idx < 9; idx++)
    {
        int gap = gaps[idx];
        for (int i = gap; ++count_compare && i < n; i++)
        {
            int v = a[i];
            int j = i;
            while (++count_compare && j >= gap && ++count_compare && a[j - gap] > v)
            {
                a[j] = a[j - gap];
                j -= gap;
            }

            a[j] = v;
        }
    }
}

void ShellSortOptimize(int a[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = a[i];

            int j = i;
            for (; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];

            a[j] = temp;
        }
    }
}

void ShellSortOptimize(int a[], int n, long long& count_compare)
{
    for (int gap = n / 2; ++count_compare && gap > 0; gap /= 2)
    {
        for (int i = gap; ++count_compare && i < n; i++)
        {
            int temp = a[i];

            int j = i;
            for (; ++count_compare && j >= gap && ++count_compare && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];

            a[j] = temp;
        }
    }
}
