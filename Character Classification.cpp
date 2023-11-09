#include "../../std_lib_facilites.h"

void printClassification(const string& word)
{
	cout << "Character classification of " << word << ": " << endl;
	for (char c : word)
	{
		cout << c << " is : ";
		if (isprint(c))
			cout << " a printable character ";
		if (isgraph(c))
			cout << " not a space ";
		if (isspace(c))
			cout << " a whitespace ";
		if (isalnum(c))
			cout << " a letter or digit ";
		if (isalpha(c))
		{
			if (isupper(c))
				cout << " an uppercase a letter ";
			if (islower(c))
				cout << " a lowercase letter ";
		}
		if (isdigit(c))
			cout << " a digit";
		if (isxdigit(c))
			cout << " a hexadecimal digit ";
		if (iscntrl(c))
			cout << " a control character ";
		if (ispunct(c))
			cout << " a punctuation character";
		cout << endl;
	}
}

int main()
{
	vector <string> words;
	cout << "Enter a set of words: ";
	for (string w; cin >> w;)
		words.push_back(w);
	cout << endl;
	for (string w : words)
		printClassification(w);
	cout << endl;



	return 0;
}