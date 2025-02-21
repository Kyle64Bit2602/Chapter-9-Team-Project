#include <iostream>
#include "InputValidation.h"
#include <memory>

using namespace std;

unique_ptr<int> getSize()
{
    unique_ptr<int> size(new int);

    cout << "Number of grades: ";
    validate_int(*size, "Enter a positive number: ", 0);

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
