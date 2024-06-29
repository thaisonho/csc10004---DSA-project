#include "FlashSort.h"

void flashSort(int* arr, int n)
{
    if (n == 0) return;

    int m = int(0.45 * n);
    if (m <= 1) {
        std::sort(arr, arr + n);
        return;
    }

    std::vector<int> L(m, 0);

    int minVal = arr[0];
    int maxVal = arr[0];
    int maxIndex = 0;

    // Find the min and max values
    for (int i = 1; i < n; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
    }

    if (minVal == maxVal) return;

    // Compute the bucket indices
    for (int i = 0; i < n; ++i) {
        int k = int(((m - 1) * (arr[i] - minVal)) / (maxVal - minVal));
        ++L[k];
    }

    // Transform L to prefix sums
    for (int i = 1; i < m; ++i) {
        L[i] += L[i - 1];
    }

    std::swap(arr[0], arr[maxIndex]);

    int move = 0, j = 0, k = m - 1;
    int flash;

    // Permutation
    while (move < n - 1) {
        while (j >= L[k]) {
            j++;
            k = int(((m - 1) * (arr[j] - minVal)) / (maxVal - minVal));
        }
        flash = arr[j];
        while (j != L[k]) {
            k = int(((m - 1) * (flash - minVal)) / (maxVal - minVal));
            int hold = arr[--L[k]];
            arr[L[k]] = flash;
            flash = hold;
            move++;
        }
    }

    // Insertion std::sort for small segments
    int start = 0;
    for (int i = 0; i < m; ++i) {
        int end = (i == m - 1) ? n : L[i];
        if (end - start > 1) {
            std::sort(arr + start, arr + end);
        }
        start = end;
    }
}

void flashSort(int* arr, int n, long long& count_compare)
{
    if (++count_compare && n == 0) return;

    int m = int(0.45 * n);
    if (++count_compare && m <= 1) {
        std::sort(arr, arr + n);
        return;
    }

    std::vector<int> L(m, 0);

    int minVal = arr[0];
    int maxVal = arr[0];
    int maxIndex = 0;

    // Find the min and max values
    for (int i = 1;++count_compare && i < n; ++i) {
        if (++count_compare && arr[i] < minVal) {
            minVal = arr[i];
        }
        if (++count_compare && arr[i] > maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
    }

    if (++count_compare && minVal == maxVal) return;

    // Compute the bucket indices
    for (int i = 0;++count_compare && i < n; ++i) {
        int k = int(((m - 1) * (arr[i] - minVal)) / (maxVal - minVal));
        ++L[k];
    }

    // Transform L to prefix sums
    for (int i = 1;++count_compare && i < m; ++i) {
        L[i] += L[i - 1];
    }

    std::swap(arr[0], arr[maxIndex]);

    int move = 0, j = 0, k = m - 1;
    int flash;

    // Permutation
    while (++count_compare && move < n - 1) {
        while (++count_compare && j >= L[k]) {
            j++;
            k = int(((m - 1) * (arr[j] - minVal)) / (maxVal - minVal));
        }
        flash = arr[j];
        while (++count_compare && j != L[k]) {
            k = int(((m - 1) * (flash - minVal)) / (maxVal - minVal));
            int hold = arr[--L[k]];
            arr[L[k]] = flash;
            flash = hold;
            move++;
        }
    }

    // Insertion std::sort for small segments
    int start = 0;
    for (int i = 0;++count_compare && i < m; ++i) {
        int end = (i == m - 1) ? n : L[i];
        count_compare++;
        if (++count_compare && end - start > 1) {
            std::sort(arr + start, arr + end);
        }
        start = end;
    }
}
