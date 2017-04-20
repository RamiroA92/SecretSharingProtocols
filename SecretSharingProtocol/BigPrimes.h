#pragma once
#ifndef BIGPRIME
#define BIGPRIME

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#include <ctime>
#include <ctime>
#include <chrono>
#include <iostream>
#include <limits>
#include <math.h>
#include <vector>

namespace mp = boost::multiprecision;

class BigPrime {
public:
	BigPrime(): bigPrime(7){ } //arbitrary selected prime
	BigPrime(int bitsize) {
		
		generateRndPrime(bitsize); //in future implementation possible choices 128, 256, 512 ..., but < than 1024
	}
	void generateRndPrime(int bitsize);
	mp::int1024_t getBigPrime() { return this->bigPrime; }

private:
	mp::int1024_t bigPrime;
	mp::int1024_t BigPrime::power(mp::int1024_t x, mp::int1024_t y, mp::int1024_t p);
	bool millerTest(mp::int1024_t d, mp::int1024_t n);
	bool isPrime(mp::int1024_t n, mp::int1024_t k);
	void gen128BitPrime();
	void gen256BitPrime();
	void gen512BitPrime();
	void gen12BitPrime();  //Default
};


//Implementation
void BigPrime::gen12BitPrime() {
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count(); //source of randmoness
	typedef boost::random::independent_bits_engine<boost::random::mt19937, 12, mp::int1024_t> generator_type;
	generator_type gen(seed);

	bool isPrime = false;
	mp::int1024_t n = gen(); //generates random integer of a given bit size size. 
	while (!this->isPrime(n, 1000)) {
		n = gen();
		std::cout << "Attempting generation of Prime: " << std::hex << std::showbase << n << std::endl;
	}
	std::cout << "\nPossible Prime: " << std::dec << std::showbase << n << std::endl;
	this->bigPrime = n;
}

void BigPrime::gen128BitPrime() {
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count(); //source of randmoness
	typedef boost::random::independent_bits_engine<boost::random::mt19937, 128, mp::int1024_t> generator_type;
	generator_type gen(seed);

	bool isPrime = false;
	mp::int1024_t n = gen(); //generates random integer of a given bit size size. 
	while (!this->isPrime(n, 1000)) {
		n = gen();
		std::cout << "Attempting generation of Prime: " << std::hex << std::showbase << n << std::endl;
	}
	std::cout << "\nPossible Prime: " << std::dec << std::showbase << n << std::endl;
	this->bigPrime = n;
}

void BigPrime::gen256BitPrime() {
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count(); //source of randmoness
	typedef boost::random::independent_bits_engine<boost::random::mt19937, 256, mp::int1024_t> generator_type;
	generator_type gen(seed);

	bool isPrime = false;
	mp::int1024_t n = gen(); //generates random integer of a given bit size size. 
	while (!this->isPrime(n, 1000)) {
		n = gen();
		std::cout << "Attempting generation of Prime: " << std::hex << std::showbase << n << std::endl;
	}
	std::cout << "\nPossible Prime: " << std::dec << std::showbase << n << std::endl;
	this->bigPrime = n;
}

void BigPrime::gen512BitPrime() {
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count(); //source of randmoness
	typedef boost::random::independent_bits_engine<boost::random::mt19937, 512, mp::int1024_t> generator_type;
	generator_type gen(seed);

	bool isPrime = false;
	mp::int1024_t n = gen(); //generates random integer of a given bit size size. 
	while (!this->isPrime(n, 1000)) {
		n = gen();
		std::cout << "Attempting generation of Prime: " << std::hex << std::showbase << n << std::endl;
	}
	std::cout << "\nPossible Prime: " << std::dec << std::showbase << n << std::endl;
	this->bigPrime = n;
}

void BigPrime::generateRndPrime(int bitsize) {
	if (bitsize == 128) {
		gen128BitPrime();
	}
	else if(bitsize == 256) {
		gen256BitPrime();
	}
	else if(bitsize == 512) {
		gen512BitPrime();
	}
	else {
		std::cout << "Default unsecure bitsize 12 was chosen: choices are 128,256,512" << std::endl;
		gen12BitPrime();
	}

}

// Utility function to do modular exponentiation.
mp::int1024_t BigPrime::power(mp::int1024_t x, mp::int1024_t y, mp::int1024_t p)
{
	mp::int1024_t res = 1;      // Initialize result
	x = x % p;  // Update x if it is more than or
				// equal to p
	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res*x) % p;

		// y must be even now
		y = y >> 1; // y = y/2
		x = (x*x) % p;
	}
	return res;
}

bool BigPrime::millerTest(mp::int1024_t d, mp::int1024_t n)
{
	// Pick a random number in [2..n-2]
	// Corner cases make sure that n > 4
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count(); //source of randmoness
	typedef boost::random::independent_bits_engine<boost::random::mt19937, 512, mp::int1024_t> generator_type;
	generator_type gen(seed);

	mp::int1024_t a = 2 + gen() % (n - 4);

	// Compute a^d % n
	mp::int1024_t x = power(a, d, n);

	if (x == 1 || x == n - 1)
		return true;

	while (d != n - 1)
	{
		x = (x * x) % n;
		d *= 2;

		if (x == 1)      return false;
		if (x == n - 1)    return true;
	}

	// Return composite
	return false;
}

// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool BigPrime::isPrime(mp::int1024_t n, mp::int1024_t k)
{
	// Corner cases
	if (n <= 1 || n == 4)  return false;
	if (n <= 3) return true;

	// Find r such that n = 2^d * r + 1 for some r >= 1
	mp::int1024_t d = n - 1;
	while (d % 2 == 0)
		d /= 2;

	// Iterate given nber of 'k' times
	for (int i = 0; i < k; i++)
		if (millerTest(d, n) == false)
			return false;

	return true;
}

#endif 