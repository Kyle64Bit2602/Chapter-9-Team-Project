#include <iostream>

using namespace std;

unique_ptr<int> getSize();
unique_ptr<double[]> enterScores(int);
void saveData(double[], int, double);
void displayData(double[], int, double);
void quickSort(double[], int, int);
unique_ptr<double> calculate_average_no_smallest(double[], int);

int main()
{
    //Gets an amount of grades, then the specific grades from the user
    //Calculates the average dropping the lowest score
    //Outputs the data to cout and results.txt

    unique_ptr<int> size(new int);
    size = getSize();

    unique_ptr<double[]> data(new double[*size]);
    data = enterScores(*size);

    quickSort(data.get(), 0, (*size-1));

    unique_ptr<double> average(new double);
    average = calculate_average_no_smallest(data.get(), *size);
    
    displayData(data.get(), *size, *average);
    saveData(data.get(), *size, *average);

    return 0;
}
