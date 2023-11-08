#include "../../std_lib_facilites.h"

int main()
{
	string iname, oname;
	cout << "Enter the input file name: ";
	cin >> iname;
	if (!cin)
		error("Wrong file name");
	ifstream inFile{ iname };
	if (!inFile)
		error("Cannot open inptu file");

	cout << "Enter the name of the output file: ";
	cin >> oname;
	if (!cin)
		error("Wrong file name");
	ofstream outFile{ oname };
	if (!outFile)
		error("Cannot open output file");

	for (char c; inFile.get(c);)
	{
		if (isalpha(c))
			outFile << static_cast<char>(tolower(c));
		else
			outFile << c;
	}


	cout << "End of program" << endl;

	return 0;
}
