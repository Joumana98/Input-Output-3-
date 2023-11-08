#include "../../std_lib_facilites.h"

int main()
{
	vector <int> nbs;
	vector <string> format;
	cout << "Enter a set of integers in any combination of octal,decimal,or hexadecimal, using 0 and 0x base suffixes: ";

	// get all numbers as strings
	for (string n; cin >> n;)
		format.push_back(n);

	string str;
	// form a string of numbers
	for (int i = 0; i < format.size(); i++)
	{
		str += format[i];
		str += " ";
	}
	// create istringstream to read numbers form it;
	istringstream is{ str };

	// To make >> understand prefixes
	is.unsetf(ios::dec);
	is.unsetf(ios::hex);
	is.unsetf(ios::oct);

	int n;
	for (int i = 0; i < format.size(); i++)
	{
		is >> n;
		nbs.push_back(n);
	}

	for (int i = 0; i < nbs.size(); i++)
	{
		if (isdigit(format[i][0]) && format[i][0] != '0')
			cout << setw(8) << format[i] << setw(12) << " decimal";

		else if (format[i][0] == '0' && (format[i][1] == 'x' || format[i][1] == 'X'))
			cout << setw(8) << format[i] << setw(12) << " hexadecimal";
		else if (format[i][0] == '0' && (format[i][1] != 'x' && format[i][1] != 'X'))
			cout << setw(8) << format[i] << setw(12) << " octal";

		cout << " converts to " << nbs[i] << " decimal" << endl;
	}

	return 0;
}