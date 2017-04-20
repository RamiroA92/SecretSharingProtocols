#pragma once
#ifndef POLYNOMIAL
#define POLYNOMIAL

/*THERE IS AN ASSUMPTION THAT THE COEFFICIENTS WILL BE SAVED IN INCREASING ORDER
FOR EXAMPLE v<mp::int1024_t> c = {1, 0 , 3}; Poly(c)
is a polynomial: 1 + 0x^1 + 3x^2*/
#include <boost/math/special_functions/pow.hpp>
#include "BigPrimes.h"
#include <iostream>
#include <math.h>
#include "utility.h"
#include <vector>

using namespace std;
namespace mp = boost::multiprecision;

class Polynomial {
public:
	Polynomial() :deg(0), coefficients(0), field(0){}
	Polynomial(vector<mp::int1024_t> v) {
		coefficients = v;
		deg = coefficients.size() - 1;
	}

	const Polynomial & operator=(const Polynomial & rhs);
	vector<mp::int1024_t> returnPolynomial() { return coefficients; }

	//the operations to define for the Polynomial class
	Polynomial operator+(const Polynomial & secondPoly);
	Polynomial operator*(const Polynomial & secondPoly);
	friend ostream& operator<<(ostream& out, const Polynomial& P);
	Polynomial genRndPrimePoly(int degree);
	int getDegree() { return deg; }
	mp::int1024_t evaluate(mp::int1024_t point);
	mp::int1024_t getField() { return field; }

private:
	int deg;
	vector<mp::int1024_t> coefficients;
	mp::int1024_t field;
};
#endif // !POLYNOMIAL

//FUNCTION DEFINITIONS
//COPY CONSTRUCTOR
const Polynomial & Polynomial::operator=(const Polynomial & rhs) {
	if (this != &rhs) {
		this->coefficients = rhs.coefficients;
		this->deg = rhs.deg;

	}
	return *this;
}

//Operaotr << overload for effortless cout output
ostream& operator<<(ostream& out, const Polynomial& P) {
	if (P.coefficients.size()) {
		out << P.coefficients[0];
		for (unsigned i = 1; i < P.coefficients.size(); i++) {
			out << " + " << P.coefficients[i] << "x^" << i;
			;
		}
	}
	return out;
}

//POLYSUM
Polynomial Polynomial::operator+(const Polynomial & secondPoly){
	int size = max(this->coefficients.size(), secondPoly.coefficients.size());
	vector<mp::int1024_t> sum(size);

	// Initialize the elements of the polynomial
	for (unsigned i = 0; i < this->coefficients.size(); i++)
		sum[i] = this->coefficients[i];
	
	// Add like terms
	for (unsigned i = 0; i < secondPoly.coefficients.size(); i++)
		sum[i] += secondPoly.coefficients[i];

	Polynomial polySum(sum); //create a return object.

	return polySum;
}

//POLY-Mulitiplication
Polynomial Polynomial::operator*(const Polynomial & secondPoly) {
	int m = this->coefficients.size();
	int n = secondPoly.coefficients.size();

	vector<mp::int1024_t> prod(m + n - 1);  // the product of two polynomials is m + n -1

	// Initialize the porduct polynomial
	for (unsigned i = 0; i < m + n - 1; i++)
		prod[i] = 0;

	// Multiply two polynomials term by term

	// Take ever term of first polynomial
	for (unsigned i = 0; i<m; i++)
	{
		// Multiply the current term of first polynomial
		// with every term of second polynomial.
		for (unsigned j = 0; j < n; j++)
			prod[i + j] += this->coefficients[i] * secondPoly.coefficients[j];
	}

	Polynomial polyMult(prod); //create a return object.
	return polyMult;
}

//Genration of random polynomial with coefficient belonging to a prime field
Polynomial Polynomial::genRndPrimePoly(int degree){
	BigPrime P;
	P.generateRndPrime(128);  // this 128 does not yet have any meaning
	mp::int1024_t field = P.getBigPrime();
	vector<mp::int1024_t> rndCoeff(degree + 1);

	//Set up of random generator
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count(); //source of randmoness
	typedef boost::random::independent_bits_engine<boost::random::mt19937, 10, mp::int1024_t> generator_type;
	generator_type gen(seed);

	mp::int1024_t coeff = gen();
	for (unsigned i = 0; i < rndCoeff.size(); i++) {
		coeff = gen();
		rndCoeff[i] = coeff % field;
	}

	Polynomial rndPoly(rndCoeff); //create a return object.

	*this = rndPoly;
	this->field = field;
	std::cout << "Random Polynomial Field: " << std::showbase << std::dec << field << std::endl;
	std::cout << "Random Polynomial: " << std:: showbase << std::dec <<*this << std::endl;
	return rndPoly;
}

//Polynomial evaluation at a given point
mp::int1024_t Polynomial::evaluate(mp::int1024_t point) {
	if (!this->coefficients.empty()) {
		mp::int1024_t result = coefficients[0];
		int index = 1;
		for (mp::int1024_t i = 1; i < coefficients.size(); i++) {
			result += bigInt_power(point, i) * this->coefficients[index];
			index++;
		}

		return result;
	}

}


