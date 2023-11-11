#include "../../std_lib_facilites.h"

vector<string> split(const string& s, const string& w)
{
	//return a vector of whitespace-seperated words
	// a whitespace is an ordinary whitespace + character is w
	vector<string> words;
	istringstream is{ s };

	ostringstream os;
	for (string x; is >> x;)
	{
		if (x != w)
			os << x << " ";
		else
		{
			words.push_back(os.str());
			os.str("");
			os.clear();

		}

	}
	if (os.str() != "")
		words.push_back(os.str());
	return words;
}

int main()
{
	string text;
	cout << "Enter a string of whites-seperated words: ";
	getline(cin, text);

	vector<string> words = split(text, "END");

	for (string x : words)
		cout << x << endl;

	return 0;
}