//Tss_driver file
#include <iostream>
#include "Polynomial.h"
#include "TSS.h"

namespace mp = boost::multiprecision;

void tss_drive() {

	int threshold;
	std::cout << "Welcome to TSS driver: enter threshold int value below" << std::endl;
	std::cout << "->  ";
	std::cin >> threshold;

	Tss Protocol(threshold);
	vector<Share> shares(threshold);
	//Sharing phase. 
	std::cout << "Lagrange Recovery: " << std::endl;
	for (unsigned i = 0; i < shares.size(); i++) {
		shares[i].x = i + 1;
		shares[i].y = Protocol.sharing(i + 1);
	}

	//recovery phase
	cout << "the secret: " << Protocol.recovery(shares, 0, Protocol.getField()) << endl;
	

}