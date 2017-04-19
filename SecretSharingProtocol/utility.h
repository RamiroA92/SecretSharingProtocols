#pragma once
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <string>
#include <vector>

namespace mp = boost::multiprecision;
using namespace std;

int Str2Int(string &s);
string stringToUpper(string  &s);
vector<string> tokenize(string com);
