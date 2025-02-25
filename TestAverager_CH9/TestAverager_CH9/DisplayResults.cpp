#include <iostream>
#include <memory>
#include <iomanip>

using namespace std;

void displayData(unique_ptr<double[]> array[], int size, double average)
{
	cout << "Sorted Grades\n";
	cout << "-------------\n";

	unique_ptr<int> index(new int);

	for (*index = 0; *index < size; *index += 1)
	{
		cout << fixed << setprecision(2) << array[*index] << "\n";
	}

	cout << "\n";
	cout << "Average\n";
	cout << "-------------\n";
	cout << fixed << setprecision(2) << average << "\n";

	return;
}