#include "counting_sort.h"
#include <iostream>

void CountingSort(int* a, int n) {
    int MAX = -2e9;
    for (int i = 0; i < n; ++i){
        if (MAX < a[i]) MAX = a[i];
    }

    int MIN = 2e9+1;
    for (int i = 0; i < n; ++i) {
        if (MIN > a[i]) MIN = a[i];
    }
    for (int i = 0; i < n; ++i) {
        a[i] = a[i] - MIN;
    }
    int *temp = new int[MAX - MIN + 1];
    for (int i = 0; i <= MAX - MIN; ++i) {
        temp[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        temp[a[i]]++;
    }
    for (int u = 1; u <= MAX - MIN; ++u){
        temp[u] = temp[u - 1] + temp[u];
    }
    int *p = new int[n];
    for (int i = n - 1; i >= 0; --i) {
        p[temp[a[i]] - 1] = a[i];
        --temp[a[i]];
    }
    for (int i = 0; i < n; ++i) a[i] = p[i] + MIN;
    delete[] temp;
}

void CountingSort(int* a, int n, long long &comparison){
    int MAX = -2e9;
    for (int i = 0; ++comparison && i < n; ++i){
        if (++comparison && MAX < a[i]){
            MAX = a[i];
        }
    }

    int MIN = 2e9+1;
    for (int i = 0; ++comparison && i < n; ++i){
        if (++comparison && MIN > a[i]){
            MIN = a[i];
        }
    }

    for (int i = 0; ++comparison && i < n; ++i){
        a[i] = a[i] - MIN;
    }

    int* temp = new int[MAX - MIN + 1];
    memset(temp, 0, (MAX - MIN + 1) * sizeof(int));
    comparison += (MAX - MIN + 1);

    for (int i = 0; ++comparison && i < n; ++i){
        temp[a[i]]++;
    }

    for (int u = 1; ++comparison && u <= MAX - MIN; ++u){
        temp[u] = temp[u - 1] + temp[u];
    }

    int* p = new int[n];
    for (int i = n - 1; ++comparison && i >= 0; --i){
        p[temp[a[i]] - 1] = a[i];
        --temp[a[i]];
    }

    for (int i = 0; ++comparison && i < n; ++i){
        a[i] = p[i] + MIN;
    }

    delete[] temp;
}
