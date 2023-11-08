#include "../../std_lib_facilites.h"

int main()
{
	string iname;
	cout << "Enter the file's name: ";
	cin >> iname;
	ifstream inFile{ iname };
	if (!inFile)
		error("Cannot open input file");
	string word;
	cout << "Entert the word to search:";
	cin >> word;

	string line;
	getline(inFile, line);
	int counter = 0;
	while (inFile)
	{
		istringstream is{ line };
		for (string w; is >> w;)
		{
			if (w == word)
			{
				cout << "Line " << counter << ": ";
				cout << line << endl;
				break;
			}

		}
		counter++;
		getline(inFile, line);
	}

	return 0;
}