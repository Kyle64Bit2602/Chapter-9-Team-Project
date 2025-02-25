#include <iostream>
#include <memory>
#include <fstream>
#include <iomanip>

using namespace std;

void saveData(double arr[], int size, double average)
{
	ofstream dataFile;
	dataFile.open("..\\..\\results.txt");

	if (!dataFile)
	{
		cout << "File Write Error!";
	}
	else
	{
		dataFile << "Sorted Grades\n";
		dataFile << "-------------\n";

		unique_ptr<int> index(new int);

		for (*index = 0; *index < size; *index += 1)
		{
			dataFile << fixed << setprecision(2) << arr[*index] << "\n";
		}

		dataFile << "\n";
		dataFile << "Average with lowest dropped\n";
		dataFile << "---------------------------\n";
		dataFile << fixed << setprecision(2) << average << "\n";
	}

	dataFile.close();
	return;
}