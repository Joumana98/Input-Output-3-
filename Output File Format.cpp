#include "../../std_lib_facilites.h"

int main()
{
	string iname;
	cout << "Enter the name of the input file: ";
	cin >> iname;

	ifstream inFile{ iname };
	if (!inFile)
		error("Input file cannot be opened!");

	string oname;
	cout << "Enter tha name of the output file: ";
	cin >> oname;
	ofstream outFile{ oname };
	if (!outFile)
		error("Output file cannot be opened!");

	int counter = 0;
	double nb;
	while (inFile >> nb)
	{
		outFile << setprecision(8) << scientific << setw(20) << nb;
		counter++;
		if (counter % 4 == 0)
			outFile << endl;
	}



	return 0;
}