#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <algorithm> // For std::swap and std::min_element
#include "InputValidation.h"
using namespace std;

// Function to calculate the average of a vector of doubles
//Only Works correctly if sorted first
unique_ptr<double> calculate_average_no_smallest(unique_ptr<double[]> arr[], int size)
{
    unique_ptr<double> sum(new double);
    for (int index = 1, *sum = 0; index < size; index++) {
        *sum += (*arr)[index];
    }
    *sum /= static_cast<double>(size);
    return sum;
}