#include "counting_sort.h"
#include <iostream>

void CountingSort(int* A, int n) {
    int k = -2e9;
    for (int i = 0; i < n; ++i){
        if (k < A[i]) k = A[i];
    }

    std::vector<int> C(k + 1, 0); // Count array
    std::vector<int> S(n); // Output array

    for (int j = 0; j <= k; ++j) {
        C[j] = 0;
    }

    for (int i = 0; i < n; ++i) {
        C[A[i]]++;
    }

    for (int j = 1; j <= k; ++j) {
        C[j] = C[j] + C[j - 1];
    }

    // Step 4: Build the output array
    for (int i = n - 1; i >= 0; --i) {
        S[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }

    for (int i = 0; i < n; ++i) {
        A[i] = S[i];
    }
}


void CountingSortImprovement(int* a, int n) {
    int MAX = -2e9;
    int MIN = 2e9+1;
    for (int i = 0; i < n; ++i){
        if (MAX < a[i]) MAX = a[i];
        if (a[i] < MIN) MIN = a[i];
    }

    int range = MAX - MIN + 1;

    std::vector<int> count(range, 0);

    // Output array to keep the array stable
    std::vector<int> output(n);

    for (int i = 0; i < n; ++i) {
        count[a[i] - MIN]++;
    }

    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        output[--count[a[i] - MIN]] = a[i];
    }

    for (int i = 0; i < n; ++i) {
        a[i] = output[i];
    }
}


void CountingSortImprovement(int* a, int n, long long& comparison) {
    int MAX = -2e9;
    int MIN = 2e9+1;
    for (int i = 0; ++comparison && i < n; ++i){
        if (++comparison && MAX < a[i]) MAX = a[i];
        if (++comparison && a[i] < MIN) MIN = a[i];
    }

    int range = MAX - MIN + 1;

    std::vector<int> count(range, 0);

    // Output array to keep the array stable
    std::vector<int> output(n);

    for (int i = 0; ++comparison && i < n; ++i) {
        count[a[i] - MIN]++;
    }

    for (int i = 1; ++comparison && i < range; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; ++comparison && i >= 0; --i) {
        output[--count[a[i] - MIN]] = a[i];
    }

    for (int i = 0; ++comparison && i < n; ++i) {
        a[i] = output[i];
    }
}



void CountingSort(int* A, int n, long long& comparison) {
    int k = -2e9;
    for (int i = 0; ++comparison && i < n; ++i){
        if (++comparison && k < A[i]) k = A[i];
    }

    std::vector<int> C(k + 1, 0);
    std::vector<int> S(n);

    for (int j = 0; ++comparison && j <= k; ++j) {
        C[j] = 0;
    }

    for (int i = 0; ++comparison && i < n; ++i) {
        C[A[i]]++;
    }

    for (int j = 1; ++comparison && j <= k; ++j) {
        C[j] = C[j] + C[j - 1];
    }

    for (int i = n - 1; ++comparison && i >= 0; --i) {
        S[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }

    for (int i = 0; ++comparison && i < n; ++i) {
        A[i] = S[i];
    }
}
