#pragma once
#ifndef POLYNOMIAL
#define POLYNOMIAL

#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
public:
	Polynomial() :deg(0), coefficients(0){}
	Polynomial(vector<int> v) {
		coefficients = v;
		deg = coefficients.size() - 1;
	}
	vector<int> returnPolynomial() { return coefficients; }
	void printPolynomial();
private:
	int deg;
	vector<int> coefficients;
};
#endif // !POLYNOMIAL

void Polynomial::printPolynomial() {
	if (coefficients.size()) {
		cout << coefficients[0];
			for (int i = 1; i < coefficients.size(); i++) {
				cout << " + x^" << i;
;			}
	}
	cout << endl;
}