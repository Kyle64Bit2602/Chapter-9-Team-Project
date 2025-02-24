#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <algorithm> // For std::swap and std::min_element
#include "InputValidation.h"
using namespace std;

// Function to calculate the average of a vector of doubles
double calculate_average(double arr[], int size)
{
    double sum = 0;
    for (double grade : arr) {
        sum += grade;
    }
    return sum / arr.size();
}

// Function to find and remove the smallest element from the array
void removeSmallest(vector<double>& arr) {
    if (arr.empty()) {
        cout << "Array is empty. No element to remove." << endl;
        return;
    }

    // Find the iterator pointing to the smallest element
    auto minIt = min_element(arr.begin(), arr.end());

    // Remove the smallest element
    arr.erase(minIt);
}