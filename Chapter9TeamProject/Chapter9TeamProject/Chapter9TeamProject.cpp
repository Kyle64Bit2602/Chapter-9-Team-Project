#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <algorithm> // For std::swap and std::min_element
#include "InputValidation.h"
using namespace std;

// Function prototypes
double calculate_average(const vector<double>&);
void saveData(const vector<double>&, double average);
int partition(vector<double>&, int, int);
void quickSort(vector<double>&, int, int);
void removeSmallest(vector<double>&);

// Function to get the size of the array from the user
unique_ptr<int> getSize()
{
    unique_ptr<int> size(new int);

    cout << "Number of grades: ";
    validate_int(*size, "Enter a positive number: ", 0);

    return size;
}

// Function to enter scores into the array
unique_ptr<double[]> enterScores(int size)
{
    unique_ptr<double[]> array(new double[size]);
    unique_ptr<int> gradeNum(new int);

    for (*gradeNum = 0; *gradeNum < size; *gradeNum += 1)
    {
        cout << "Enter grade " << (*gradeNum + 1) << ": ";
        validate_double(array[*gradeNum], "Enter a valid grade: ", 0, 100);
    }

    return array;
}

int main()
{
    // Get the number of grades from the user
    unique_ptr<int> size = getSize();

    // Enter the grades
    unique_ptr<double[]> scores = enterScores(*size);

    // Convert array to vector for manipulation
    vector<double> scoresVector(scores.get(), scores.get() + *size);

    // Remove the smallest grade
    removeSmallest(scoresVector);
    cout << "Grades after removing the smallest: ";
    for (double grade : scoresVector) {
        cout << grade << " ";
    }
    cout << endl;

    // Calculate the average of the remaining grades
    double average = calculate_average(scoresVector);
    cout << "Average grade (after removing the smallest): " << average << endl;

    // Save data to file
    saveData(scoresVector, average);

    // Sort the grades (optional, for display purposes)
    quickSort(scoresVector, 0, scoresVector.size() - 1);
    cout << "Sorted grades: ";
    for (double grade : scoresVector) {
        cout << grade << " ";
    }
    cout << endl;

    return 0;
}

// Function to calculate the average of a vector of doubles
double calculate_average(const vector<double>& arr)
{
    if (arr.empty()) {
        return 0.0; // Avoid division by zero
    }

    double sum = 0;
    for (double grade : arr) {
        sum += grade;
    }
    return sum / arr.size();
}

// Function to save data to a file
void saveData(const vector<double>& arr, double average)
{
    ofstream dataFile;
    dataFile.open("..\\..\\results.txt");

    if (dataFile.is_open()) {
        dataFile << "Grades: ";
        for (double grade : arr) {
            dataFile << grade << " ";
        }
        dataFile << "\nAverage: " << average << endl;
        dataFile.close();
    }
    else {
        cerr << "Unable to open file for writing." << endl;
    }
}

// Function to partition the array and return the pivot index
int partition(vector<double>& arr, int low, int high) {
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
void quickSort(vector<double>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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