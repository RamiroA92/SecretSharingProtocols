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


mp::int1024_t bigInt_power(mp::int1024_t base, mp::int1024_t power) {

		mp::int1024_t result = 1;
		while (power > 0) {

			if (power % 2 == 1) { // Can also use (power & 1) to make code even faster
				result = (result*base);
			}
			base = (base * base);
			power = power / 2; // Can also use power >>= 1; to make code even faster
		}
		return result;
	
}


//Extend euclid's algortithm to find Bezout coefficients
mp::int1024_t gcdExtended(mp::int1024_t a, mp::int1024_t b, mp::int1024_t *x, mp::int1024_t *y) {
	// Base Case
	if (a == 0)
	{
		*x = 0;
		*y = 1;
		return b;
	}

	mp::int1024_t x1, y1; // To store results of recursive call
	mp::int1024_t gcd = gcdExtended(b%a, a, &x1, &y1);

	// Update x and y using results of recursive
	// call
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}


mp::int1024_t modLagrange(vector<Share> f, mp::int1024_t xi, mp::int1024_t m)
{
	mp::int1024_t result = 0; // Initialize result
	mp::int1024_t inv;
	mp::int1024_t y;

	for (int i = 0; i < f.size(); i++)
	{
		mp::int1024_t term = f[i].y;
		for (int j = 0; j < f.size(); j++)
		{
			if (j != i) {
				mp::int1024_t d = f[j].x - f[i].x;
				while (d < 0) {
					d = d + m;
				}
				gcdExtended(d, m, &inv, &y);
				while (inv < 0) {
					inv = inv + m;
				}
				term = term * f[j].x * inv;
				term = term % m;
			}
		}
		// Add current term to result
		result += term;
	}
	while (result < 0)
	{
		result = result + m;
	}
	result %= m;
	return result;
}