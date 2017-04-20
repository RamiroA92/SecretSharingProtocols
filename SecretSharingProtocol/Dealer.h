#pragma once
#ifndef DEALER
#define DEALER

#include "Player.h"

class Dealer {
public:
	//Constructors
	Dealer() {}
	//Operations
	void initiateTss(vector<Player> & players);
	void initiateTss(vector<Player> & players, mp::int1024_t s);

private:
	
};

//Implementation
void Dealer::initiateTss(vector<Player> & players) {
	Tss tss(players.size());
	for (unsigned i = 0; i < players.size(); i++) {
		players[i].setPlayerID(i + 1);
		players[i].setSecret(tss.sharing(players[i].getId()));
	}
}
void Dealer::initiateTss(vector<Player> & players, mp::int1024_t s){
	Tss tss(players.size());
	tss.insertSecret(s);
	for (unsigned i = 0; i < players.size(); i++) {
		players[i].setPlayerID(i + 1);
		players[i].setSecret(tss.sharing(players[i].getId()));
	}
}

#endif // !1
