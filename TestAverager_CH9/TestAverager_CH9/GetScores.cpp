#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <algorithm> // For std::swap and std::min_element
#include "InputValidation.h"

using namespace std;

unique_ptr<int> getSize()
{
    unique_ptr<int> size(new int);

    cout << "Number of grades: ";
    validate_int(*size, "Enter a positive number of at least 2: ", 2);

    return size;
}

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
