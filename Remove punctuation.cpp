// get rid of punctuation in a string

#include "../../std_lib_facilites.h"

class Punct_stream
{
public:

	//constructor
	Punct_stream(istream& is) : source{ is }, sensitive{ true } {}

	//accessors
	bool is_whitespace(char c);
	bool is_case_sensitive() { return sensitive; }

	//mutators
	void whitespace(const string& s) { white = s; } // set the list of whitespcaes
	void add_whitespace(char c) { white += c; }// add to the whitespace set
	void case_sensitive(bool b) { sensitive = b; }

	//operators
	Punct_stream& operator>> (string& s);
	operator bool();

private:
	istream& source; //character source
	istringstream buffer; // we let buffer do our formatting
	string white; //character considered as whitespaces
	bool sensitive; // is the stream case sensitive?

	//this class can convert case-sensitive input to non-case_sensitive input
};

int main()
{
	// given text input, produce a sorted list of all words in that text
	// ignore punctuation and case differences
	// eliminate duplicates from the output

	Punct_stream ps{ cin };
	ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~");
	ps.case_sensitive(false);

	cout << "Please enter words: ";
	vector<string> vs;
	for (string word; ps >> word; )
		vs.push_back(word);

	sort(vs.begin(), vs.end());
	for (int i = 0; i < vs.size(); i++) // write dictionary
	{
		if (i == 0 || vs[i] != vs[i - 1]) // skip duplicates
			cout << vs[i] << endl;
	}


	return 0;
}

Punct_stream& Punct_stream::operator>>(string& s)
{
	// try to read form the buffer,and only when we find it empty, we try to fill it

	while (!(buffer >> s)) // if there are characters in buffer, the read will work
		// and s will receive whitespace seperated words, then there is nothing more to do
	{
		if (buffer.bad() || !source.good()) // source became not good, or buffer is bad
			return *this; // return a reference to the stream itself

		buffer.clear(); // read failed because buffer is empty, clear stream state

		string line;
		getline(source, line); // get line from source

		// do character replacement as needed
		for (char& c : line)
		{
			if (is_whitespace(c))
				c = ' ';
			else if (!sensitive)
				c = tolower(c);
		}

		buffer.str(line); //set buffer's string to a copy of line after it's changed
	}

	return *this;
}

bool Punct_stream::is_whitespace(char c)
{
	for (char w : white)
		if (c == w) return true;
	return false;
}


Punct_stream::operator bool() // look at the results of ps>>s as a boolean value
// the result of ps >> s is a Punct_stream,so we need a way of implicitly turning a Punct_stream into a bool
//returns true if the operation on the Punct_stream succeeded
{
	return !(source.fail() || source.bad()) && source.good();
}