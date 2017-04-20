#pragma once
#include <iostream>
#include "Polynomial.h"
#include "TSS.h"

void custom_tss() {
	string com;
	cin >> com;
	vector<string> tokens = tokenize(com);
	vector<mp::int1024_t> coeff(tokens.size());

	for (int i = 0; i < coeff.size(); i++) {
		coeff[i] =(Str2Int(tokens[i]));
		cout << coeff[i];
	}

}