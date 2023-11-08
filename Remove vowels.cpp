#include "../../std_lib_facilites.h"

class Vowel_type
{
public:
	//constructor
	Vowel_type(istream& in) : source{ in } {};

	//accessors
	bool is_vowel(char c);

	//mutators
	void setVowels(const string& v) { vowels = v; }
	void addVowel(char ch) { vowels += ch; }

	//operator
	Vowel_type& operator>> (string& s);
	operator bool();

private:
	istream& source; //characters source
	string vowels; // string containing vowels set
	istringstream buffer; // let the buffer do our formatting

};

int main()
{
	string iname;
	cout << "Enter the input file's name: ";
	cin >> iname;
	fstream ioFile{ iname };
	if (!ioFile)
		error("Cannot open input file");

	Vowel_type vt{ ioFile };
	vt.setVowels("aeiouy");

	for (string word; vt >> word;)
		cout << word << " ";

	return 0;
}

bool Vowel_type::is_vowel(char c)
{
	for (char ch : vowels)
	{
		if (c == ch)
			return true;
	}
	return false;
}

Vowel_type& Vowel_type::operator>> (string& s)
{
	while (!(buffer >> s)) // couldn't fill the string (string is filled word by word)
	{
		if (buffer.bad() || !source.good()) // source became not good, or buffer is bad: give up
			return *this;

		// try to fill the buffer
		buffer.clear(); // read failed because buffer is empty, clear stream state

		string line;
		getline(source, line); // get line from source;

		// need to remove vowels and then fill the buffer
		for (char& c : line)
		{
			if (is_vowel(c))
				c = '\0';
		}
		//cout << line << endl;
		buffer.str(line); //set buffer's string to a copy of line after it's changed
	}

	return *this;
}

Vowel_type::operator bool() // look at the results of vt>>s as a boolean value
{
	return !(source.fail() || source.bad()) && source.good();
}