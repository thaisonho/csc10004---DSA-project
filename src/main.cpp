#include "DataGenerator.h"
#include "QuickSort.h"
#include "radix_sort.h"
#include "timeBenchmark.h"
#define ARR_SIZE 100000

using namespace std;

int main() {
    // Example
    int arr[ARR_SIZE], tmp_arr[ARR_SIZE], cnt = 0;
    // random array
    GenerateData(arr, ARR_SIZE, 0);
    memcpy(tmp_arr, arr, ARR_SIZE * sizeof(int));
    cout << funcRunTime(quickSort, arr, 0, ARR_SIZE) << '\n';
    quickSort(tmp_arr, 0, ARR_SIZE, cnt);
    cout << "Comparison in Quicksort: " << cnt;
}