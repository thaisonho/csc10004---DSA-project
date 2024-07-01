#include "SortAlgorithm.h"
#include "timeBenchmark.h"
#include "DataGenerator.h"
#include <string>
#include <iostream>
#include <fstream>
#include <utility>

using namespace std;

const string Name[] =
{
    "Selection Sort", "Insertion Sort", "Bubble Sort", "Shaker sort",
    "Shell Sort", "Heap Sort", "Merge Sort", "Quick Sort",
    "Counting sort", "Radix Sort", "Flash Sort"
};

const string DataOrder[] =
{
    "Randomized Data", "Nearly Sorted Data",
    "Sorted Data", "Reverse Sorted Data"
};

int GetSortName(const string &sortName);
int GetInputOrder(const string &inputOrder);
int GetOutputParameter(const string &outputParameter);

void OutputRuntime(int a[], int inputSize, const string &sortName, int command_type);
void OutputComparisons(int a[], int inputSize, const string &sortName, int command_type);
void OutputArray(const string &filePath, int a[], int inputSize);
void OutputParameter(int type, int A[], int inputSize, const string &sortName);

void CopyArray(int a[], int b[], int inputSize);

bool AlgorithmMode(int argc, char *argv[]);
bool ComparisonMode(int argc, char *argv[]);
