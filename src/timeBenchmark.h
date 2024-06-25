#ifndef TIME_BENCHMARK_H
#define TIME_BENCHMARK_H

#include <chrono>
#include <cstddef>

/**
 * Calculates the runtime of a function that takes an array and its size as parameters.
 * 
 * @param func A pointer to the function to be benchmarked.
 * @param arr A pointer to the array.
 * @param n The size of the array.
 * @return The runtime of the function in seconds.
 */
double funcRunTime(void(*func)(int*, std::size_t), int* arr, std::size_t n);

/**
 * Calculates the runtime of a function that takes an array and an integer as parameters.
 * 
 * @param func A pointer to the function to be benchmarked.
 * @param arr A pointer to the array.
 * @param n The integer parameter.
 * @return The runtime of the function in seconds.
 */
double funcRunTime(void(*func)(int*, int), int* arr, int n);
double funcRunTime(void(*func)(int*, int, int), int* arr, int l, int r);

#endif  //TIME_BENCHMARK_H