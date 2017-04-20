//Secret Sharing protocol.cpp : Defines the entry point fpr the console application
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

#include "BigPrimes.h"
#include "Polynomial.h"
#include "tss_driver.h"

namespace mp = boost::multiprecision;

int main(int argc, char *argv []) {

	std::string response;
	do {
		tss_drive();
		cout << "do you want to run it again?\n-> ";
		cin >> response;
	} while (response != "Q" && response != "q");
	return 0;
}