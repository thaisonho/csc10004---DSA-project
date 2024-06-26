#include "DataGenerator.h"
#include "QuickSort.h"
#include "radix_sort.h"
#include "timeBenchmark.h"
#include "insertion_sort.h"
#include "counting_sort.h"
#include "merge_sort.h"
#define ARR_SIZE 100000

using namespace std;

int main() {
    // Example
    int* arr = new int[ARR_SIZE]; 
    int* tmp_arr = new int[ARR_SIZE]; 
    long long cnt = 0;
    // random array
    GenerateData(arr, ARR_SIZE, 3);
    memcpy(tmp_arr, arr, ARR_SIZE * sizeof(int));
    cout << funcRunTime(MergeSort, arr, ARR_SIZE) << '\n';
    MergeSort(tmp_arr, ARR_SIZE, cnt);
    cout << "Comparison in Counting Sort: " << cnt << '\n';
}