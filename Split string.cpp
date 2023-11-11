#include "../../std_lib_facilites.h"

vector<string> split(const string& s)
{
	vector<string> words;
	istringstream is{ s };
	for (string w; is >> w;)
		words.push_back(w);

	return words;

}

int main()
{
	string text;
	cout << "Enter a string of whites-seperated words: ";
	getline(cin, text);

	vector<string> words = split(text);

	for (string x : words)
		cout << x << endl;

	return 0;
}