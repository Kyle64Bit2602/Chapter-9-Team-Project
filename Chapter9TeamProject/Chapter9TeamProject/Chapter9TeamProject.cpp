#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
using namespace std;

int calculate_average(int[]);
int save_to_file(int[]);
int partition(vector<int>&, int, int);
void quickSort(vector<int>&, int, int);
void removeSmallest(vector<int>&);
int main()
{
    
}
int calculate_average(int[])
{
    
}
int save_to_file(int[])
{

}
// Function to partition the array and return the pivot index
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;        // Index of the smaller element

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
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to find and remove the smallest element from the array
void removeSmallest(vector<int>& arr) {
    if (arr.empty()) {
        cout << "Array is empty. No element to remove." << endl;
        return;
    }

    // Find the iterator pointing to the smallest element
    auto minIt = min_element(arr.begin(), arr.end());

    // Remove the smallest element
    arr.erase(minIt);
}
