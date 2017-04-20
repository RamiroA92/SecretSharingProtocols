#pragma once
#ifndef TSS
#define TSS

#include "Polynomial.h"
#include "Share.h"
#include "utility.h"  //Lagrange

class Tss {
public:
	Tss() {}
	Tss(Polynomial & P, mp::int1024_t f) { Poly = P; Poly.setField(f); }
	Tss(int threshold) { Poly  = Poly.genRndPrimePoly(threshold-1); }
	mp::int1024_t sharing(mp::int1024_t id);
	mp::int1024_t Tss::recovery(vector<Share> shares, mp::int1024_t xi, mp::int1024_t m);
	void setPoly(Polynomial & P, mp::int1024_t f) { Poly = P; Poly.setField(f); }
	int getPolyDegree() { cout << Poly << endl; return Poly.getDegree(); }
	mp::int1024_t getField() { return Poly.getField(); }
	void insertSecret(mp::int1024_t s) { Poly.changeFreeVariable(s); };
private:
	Polynomial Poly;
};

#endif // !TSS

//Implementation
mp::int1024_t Tss::sharing(mp::int1024_t id) {
	if (Poly.getField() != 0)
		return (Poly.evaluate(id) % Poly.getField());
	else
		return 0;
}

mp::int1024_t Tss::recovery(vector<Share> shares, mp::int1024_t xi,mp::int1024_t m) {
	
	return modLagrange(shares,xi,m);
}



