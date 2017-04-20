/*#pragma once
#include <iostream>
#include "Polynomial.h"
#include "TSS.h"

void tss_simple_example() {
	vector<mp::int1024_t> v = { 5, 3, 6 }; // Poly coefficients
	Polynomial P(v);
	Tss Protocol;  //Choose the above poly for the Tss protocol
	Protocol.setPoly(P, 13); //set Poly and field;

	vector<Share> shares(3);
	mp::int1024_t id = 1;
	//Sharing phase. 
	std::cout << "Welcome to TSS driver: class example" << std::endl;
	for (unsigned i = 0; i < shares.size(); i++) {
		shares[i].setX(id);
		shares[i].setY(Protocol.sharing(id));
		id++;
		std::cout << "Player id: " << shares[i].getX() << std::endl;
		std::cout << "f(" << i + 1 << ")" << " = " << shares[i].getY() << std::endl;
	}
	//recovery phase
	mp::int1024_t theSecret = Protocol.recovery(shares);

	std::cout << "The secret is: " << theSecret << std::endl;

}*/