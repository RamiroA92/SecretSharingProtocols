//Secret Sharing protocol.cpp : Defines the entry point fpr the console application
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

#include "BigPrimes.h"
#include "Polynomial.h"

namespace mp = boost::multiprecision;

int main(int argc, char *argv []) {

	std::cout << "testing random prime and random polynomial generation" << std::endl;
	Polynomial Poly;
	Poly.genRndPrimePoly(5);

	return 0;
}