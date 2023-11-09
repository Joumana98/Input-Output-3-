#include "../../std_lib_facilites.h"

class Punct_type
{
public:
	//constructor	
	Punct_type(istream& in) : source{ in }, sensitive{ true } {}

	//accessors
	bool getSensitive() const { return sensitive; }
	bool isPunctuation(char c) const;

	//mutators
	void setPunctuation(const string& s) { punctuations = s; }
	void addPunctuation(char c) { punctuations += c; }
	void setSensitive(bool s) { sensitive = s; }

	//operators
	Punct_type& operator>> (string& s);
	operator bool();

private:
	istream& source;
	istringstream buffer;
	string punctuations;
	bool sensitive;
};

int main()
{
	string iname;
	cout << "Enter the input file's name: ";
	cin >> iname;
	ifstream inFile{ iname };
	if (!inFile)
		error("File cannot be opened");

	Punct_type ps{ inFile };
	ps.setPunctuation(".,;?-");
	ps.setSensitive(false);

	vector<string> text;
	for (string word; ps >> word; )
		text.push_back(word);

	sort(text.begin(), text.end());
	for (int i = 0; i < text.size(); i++)
	{
		if (i == 0 || text[i] != text[i - 1])
			cout << text[i] << endl;
	}

	return 0;
}

bool Punct_type::isPunctuation(char c) const
{
	for (char ch : punctuations)
	{
		if (c == ch)
			return true;
	}
	return false;
}

Punct_type& Punct_type::operator>> (string& s)
{
	while (!(buffer >> s))
	{
		if (!(source.good()) || buffer.bad())
			return*this;

		buffer.clear();

		// get a line from the source
		string line;
		getline(source, line);

		// change some abbreviated words
		istringstream is{ line };

		string modified = "";
		ostringstream os{ modified };

		string word;
		while (is >> word)
		{
			if (word == "don't")
				os << "do not";
			else if (word == "doesn't")
				os << "does not";
			else if (word == "won't")
				os << "will not";
			else if (word == "can't")
				os << "cannot";
			else if (word == "wasn't")
				os << "was not";
			else if (word == "weren't")
				os << "were not";
			else
				os << word;
			os << " ";

		}

		line = os.str();

		// remove the punctuation and add it to the buffer
		for (char& c : line)
		{
			if (isPunctuation(c))
				c = ' ';
			else if (sensitive == false)
				c = tolower(c);
		}

		buffer.str(line);
	}

	return *this;

}

Punct_type::operator bool()
{
	return !(source.fail() || source.bad()) && source.good();
}
