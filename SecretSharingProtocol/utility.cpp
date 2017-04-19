#include "utility.h"

/*==============================================================
			CLI USEFUL TOOLS									|
================================================================*/
// A string to integer conversion 
int Str2Int(string &s)
{
	return atoi(s.c_str());
}

//To be used to deal with case sensitivity in the cli.
string stringToUpper(string & s)
{
	for (unsigned int i = 0; i<s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}
	return s;
}

//Tokenizer of CLI strings
vector<string> tokenize(string com)
{
	istringstream is(com);
	vector<string> vs;
	if (com.length() == 0)return vs;
	if ((com[0] == '/') && (com[1] == '/')) return vs;
	string s;
	char eoi = is.eof();	//e.o.i end of input;

	while (!is.eof())
	{
		if (vs.size() == 0)
		{
			getline(is, s, ' ');
		}
		else
		{
			getline(is, s, eoi);
		}
		vs.push_back(s);
	}
	return vs;
}


