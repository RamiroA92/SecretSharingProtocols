#pragma once
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <string>
#include <vector>
#include "Share.h"

namespace mp = boost::multiprecision;
using namespace std;

//CLI
int Str2Int(string &s);
string stringToUpper(string  &s);
vector<string> tokenize(string com);

//Crypto
mp::int1024_t gcdExtended(mp::int1024_t a, mp::int1024_t b, mp::int1024_t *x, mp::int1024_t *y);
mp::int1024_t bigInt_power(mp::int1024_t base, mp::int1024_t power);


mp::int1024_t modLagrange(vector<Share> f, mp::int1024_t xi, mp::int1024_t m);

