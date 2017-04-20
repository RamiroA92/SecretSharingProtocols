//Tss_driver file
#include <iostream>
#include "Polynomial.h"
#include "TSS.h"
#include <string>

namespace mp = boost::multiprecision;

void tss_drive() {

	int threshold;
	std::cout << "Welcome to TSS driver: enter threshold int value below" << std::endl;
	std::cout << "->  ";
	std::cin >> threshold;

	Tss Protocol(threshold);
	vector<Share> shares(threshold);
	mp::int1024_t id = 1;
	//Sharing phase. 
	std::cout << "Player Shares: " << std::endl;
	for (unsigned i = 0; i < shares.size(); i++) {
		shares[i].setX(id);
		shares[i].setY(Protocol.sharing(i+1));
		id++;
		std::cout << "Player id: " << shares[i].getX() << std::endl;
		std::cout << "f(" << i+1 << ")" << " = " << shares[i].getY() << std::endl;
	}

	//recovery phase
	mp::int1024_t theSecret = Protocol.recovery(shares);

	std::cout << "The secret is: " << theSecret << std::endl;
}