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
    int* tmp_arr2 = new int[ARR_SIZE]; 
    int* tmp_arr3 = new int[ARR_SIZE]; 
    long long cnt1 = 0;
    long long cnt2 = 0;
    // random array
    GenerateData(arr, ARR_SIZE, 3);
    memcpy(tmp_arr, arr, ARR_SIZE * sizeof(int));
    memcpy(tmp_arr2, arr, ARR_SIZE * sizeof(int));
    memcpy(tmp_arr3, arr, ARR_SIZE * sizeof(int));
    
    cout << funcRunTime(CountingSort, arr, ARR_SIZE) << '\n';
    CountingSort(tmp_arr, ARR_SIZE, cnt1);
    cout << "Comparison in Counting Sort: " << cnt1 << '\n';

    cout << "-------Improvement---------" << endl;

    cout << funcRunTime(CountingSortImprovement, tmp_arr2, ARR_SIZE) << '\n';
    CountingSortImprovement(tmp_arr3, ARR_SIZE, cnt2);
    cout << "Comparison in Counting Sort: " << cnt2 << '\n';
}