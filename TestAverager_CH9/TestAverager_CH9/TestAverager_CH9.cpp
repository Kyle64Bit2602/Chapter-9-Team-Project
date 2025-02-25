#include <iostream>

using namespace std;

unique_ptr<int> getSize();
unique_ptr<double[]> enterScores(int);
void saveData(unique_ptr<double[]>[], int, double);
void displayData(unique_ptr<double[]>[], int, double);
void quickSort(unique_ptr<double[]>[], int, int);
double calculate_average_no_smallest(unique_ptr<double[]>[], int);

int main()
{
    //Gets an amount of grades, then the specific grades from the user
    //Calculates the average dropping the lowest score
    //Outputs the data to cout and results.txt

    unique_ptr<int> size(new int);
    size = getSize();

    unique_ptr<double[]> data(new double[*size]);
    data = enterScores(*size);

    quickSort(data, 0, *size);

    unique_ptr<double> average(new double);
    *average = calculate_average_no_smallest(data, *size);
    
}
