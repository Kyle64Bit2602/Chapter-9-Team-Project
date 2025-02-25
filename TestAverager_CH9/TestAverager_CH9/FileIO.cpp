#include <iostream>
#include <memory>
#include <fstream>
#include <iomanip>

using namespace std;

void saveData(unique_ptr<double[]> array[], int size, double average)
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
			dataFile << fixed << setprecision(2) << array[*index] << "\n";
		}

		dataFile << "\n";
		dataFile << "Average\n";
		dataFile << "-------------\n";
		dataFile << fixed << setprecision(2) << average << "\n";
	}

	dataFile.close();
	return;
}