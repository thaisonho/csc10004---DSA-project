#include "insertion_sort.h"
    // original Insertion Sort without comparision count
    void InsertionSort(int* a, int n)
    {
        for (int i = 1; i < n; i++)
        {
            int value = a[i];
            int j = i - 1;
            while (a[j] > value && j >= 0)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = value;
        }
    }
    void BinaryInsertionSort(int* a, int n){
        for (int i = 1; i < n; ++i) {
            int value = a[i];
            int start = 0;
            int end = i - 1;

            // apply binary search to find suitabe pivot to insert
            while (start <= end) {
                int mid = (start + end) / 2;
                if (a[mid] < value) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            // shift element to add at pivot
            for (int j = i - 1; j >= start; --j) {
                a[j + 1] = a[j];
            }

            // Insert val at the correct position
            a[start] = value;
        }
    }
    // original Insertion Sort with comparision count
    void InsertionSort(int* a, int n, long long& comparison)
    {
        for (int i = 1; ++comparison && i < n; i++)
        {
            int value = a[i];
            int j = i - 1;
            while (++comparison && a[j] > value && ++comparison && j >= 0)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = value;
        }
    }
    void BinaryInsertionSort(int* a, int n, long long& comparison)
    {
        for (int i = 1; ++comparison && i < n; i++)
        {
            int value = a[i];
            int start = 0;
            int end = i - 1;
            while (++comparison && start <= end)
            {
                int mid = (start + end) / 2;
                if (++comparison && a[mid] < value)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            for (int j = i - 1; ++comparison && j >= start; j--)
                a[j + 1] = a[j];
            a[start] = value;
        }
    }