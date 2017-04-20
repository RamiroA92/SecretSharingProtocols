#pragma once
#ifndef SHARE
#define SHARE

#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

namespace mp = boost::multiprecision;
using namespace std;

class Share {
private:
public:
	Share():x(0), y(0)  {}
	mp::int1024_t x;
	mp::int1024_t y;
};
#endif // !1
