#include "../../std_lib_facilites.h"

int main()
{
	cout << "Please enter input file name: ";
	string iname2;
	cin >> iname2;

	ifstream inFile2{ iname2 };
	if (!inFile2)
		error("Can't open input file ", iname2);

	cout << "Please enter output file name: ";
	string oname2;
	cin >> oname2;
	ofstream outFile2{ oname2,ios_base::binary }; // open file in binary mode: write data as sequence of bytes
	if (!outFile2)
		error("Can't open output file ", oname2);

	for (char x; inFile2.get(x);)
		outFile2.write(as_bytes(x), sizeof(char));

	//------------------------------------------------------------------------------------------

	cout << "Please enter input file name: ";
	string iname1;
	cin >> iname1;

	ifstream inFile1{ iname1,ios_base::binary }; // open file in binary mode: read the data as sequence of bytes
	if (!inFile1)
		error("Can't open input file ", iname1);

	cout << "Please enter output file name: ";
	string oname1;
	cin >> oname1;
	ofstream outFile1{ oname1 };

	for (char x; inFile1.read(as_bytes(x), sizeof(char));)
		outFile1 << x;

	return 0;
}