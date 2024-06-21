#include "../include/algorithms/radix_sort.h" 
#include "../include/utils/DataGenerator.cpp"
#include <iostream>

using namespace std;

int main() {
    int arr[500];
    GenerateData(arr, 500, 0);
    unsigned int cnt_cmp = 0;
    radixSort(arr, 500, cnt_cmp);
    for(int i : arr) cout << i << ' ';
    cout << "\nComparisons: " << cnt_cmp;
}