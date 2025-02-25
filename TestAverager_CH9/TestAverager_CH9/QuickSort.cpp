#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <algorithm> // For std::swap and std::min_element
#include "InputValidation.h"
using namespace std;

// Function to partition the array and return the pivot index
int partition(double arr[], int low, int high) {
    double pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;           // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment the index of the smaller element
            swap(arr[i], arr[j]);
        }
    }
    // Swap the pivot element with the element at index (i + 1)
    swap(arr[i + 1], arr[high]);
    return i + 1;  // Return the partition index
}

// The main QuickSort function
void quickSort(double arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}