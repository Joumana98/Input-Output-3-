#include "../../std_lib_facilites.h"

int main()
{
	string iname;
	cout << "Enter the name of the input file: ";
	cin >> iname;

	ifstream inFile{ iname };
	if (!inFile)
		error("Input file cannot be opened!");

	vector <double> nbs;
	double nb;
	while (inFile >> nb)
		nbs.push_back(nb);

	sort(nbs.begin(), nbs.end());

	for (double x : nbs)
		cout << x << " ";
	cout << endl;


	return 0;
}