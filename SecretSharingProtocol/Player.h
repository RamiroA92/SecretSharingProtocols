#pragma once
#ifndef PLAYER
#define PLAYER

#include "TSS.h"
using namespace std;

class Player{
public:
	//Constructors
	Player() { secret = 0; playerId = 0; }
	Player(mp::int1024_t s, int id) { secret = s; playerId = id; }

	//Operations
	mp::int1024_t getSecret() { return secret; }
	int getId() { return playerId; }
	void setSecret(mp::int1024_t s) { secret = s; }
	void setPlayerID(int id) { playerId = id; }
	void insertShare(Share s) { receivedPlayers.push_back(s); };
	friend ostream& operator<<(ostream& out, const Player& Pl) {
		for (unsigned i = 0; i < Pl.receivedPlayers.size(); i++) {
			out << "From Player: " << Pl.receivedPlayers[i].x;
			out<< "\treceived: " << Pl.receivedPlayers[i].y << endl;
		}
		return out;
	}
	Share sendAShare() { Share temp; temp.x = playerId; temp.y = secret; return temp; }
private:
	Polynomial Poly;
	mp::int1024_t secret;
	int playerId;
	vector<Share> receivedPlayers; //received shared at any given time.
};

#endif // !1



