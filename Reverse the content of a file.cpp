#include "../../std_lib_facilites.h"

int main()
{
	string fileName;
	cout << "Enter the name of the file: ";
	cin >> fileName;

	fstream fEnd{ fileName };
	if (!fEnd)
		error("Cannot open the file");

	// move get and put positions to the ned of the file
	int counter = -1;
	fEnd.seekg(counter, ios::end);

	fstream outFile{ "C:\\temp.txt" };

	char ce;
	while (fEnd.get(ce))
	{
		outFile << ce;
		counter--;
		fEnd.seekg(counter, ios::end);

	}
	outFile.close();

	//delete the content of the original text file
	fEnd.open(fileName, ios::out | ios::trunc);
	fEnd.close();

	fEnd.open(fileName, ios::out);
	outFile.open("C:\\temp.txt", ios::in);
	char x;
	while (outFile.get(x))
	{
		fEnd << x;
	}


	return 0;
}