#include <iostream>
#include <memory>
#include <iomanip>

using namespace std;

void displayData(double arr[], int size, double average)
{
	cout << "Sorted Grades\n";
	cout << "-------------\n";

	unique_ptr<int> index(new int);

	for (*index = 0; *index < size; *index += 1)
	{
		cout << fixed << setprecision(2) << arr[*index] << "\n";
	}

	cout << "\n";
	cout << "Average with lowest dropped\n";
	cout << "---------------------------\n";
	cout << fixed << setprecision(2) << average << "\n";

	return;
}