#pragma once
#ifndef TSS
#define TSS

#include "Polynomial.h"
#include "Share.h"
#include "utility.h"  //Lagrange

class Tss {
public:
	Tss(int threshold) { Poly  = Poly.genRndPrimePoly(threshold-1); }
	mp::int1024_t sharing(mp::int1024_t id);
	mp::int1024_t recovery(vector< Share > shares);
private:
	Polynomial Poly;
};

mp::int1024_t Tss::sharing(mp::int1024_t id) {
	return Poly.evaluate(id) % Poly.getField();
}

mp::int1024_t Tss::recovery(vector< Share >  shares) {
	return modLagrange(shares, Poly.getField());
}

#endif // !TSS

