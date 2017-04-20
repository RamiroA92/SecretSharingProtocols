#pragma once
#ifndef SHARE
#define SHARE

#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;

class Share {
private:
	mp::int1024_t x;
	mp::int1024_t y;
public:
	Share():x(0), y(0)  {}
	Share(mp::int1024_t id, mp::int1024_t evaluation){
		x = id;
		y = evaluation;
	}
	mp::int1024_t getX() { return x; }
	mp::int1024_t getY() { return y; }
	void setX(mp::int1024_t value) { x = value; }
	void setY(mp::int1024_t value) { y = value; }
};
#endif // !1
