//Secret Sharing protocol.cpp : Defines the entry point fpr the console application

#include <iostream>
#include "BigPrimes.h"
#include "Polynomial.h"
#include "tss_driver.h"
#include "tss_class_example.h"
#include "custom_TSS.h"
#include "Player.h"
#include "Dealer.h"

namespace mp = boost::multiprecision;

int main(int argc, char *argv []) {
	
	string res;
	do {
		tss_drive();
		cout << "Run a TSS drive again?\n -> ";
		cin>> res;
		while (res != "y" && res != "q") { cout << "valid responses: y: yes, q: quit\n ->";  cin >> res; }
	} while (res != "Q" && res != "q"); 
	
	/*vector<Player> players(5);
	Dealer dealer;
	dealer.initiateTss(players);

	//Lets make Player one obtain all the shares so he can break the original secret:
	for (unsigned i = 0; i < players.size(); i++) {
		players[0].insertShare(players[i].sendAShare());
	}

	cout << players[0] << endl; */
	return 0;
}