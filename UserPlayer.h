#pragma once
#include "GenericPlayer.h"

class UserPlayer : public GenericPlayer{
private:
	std::string id;
public:
	UserPlayer(std::string name, std::string id);
	UserPlayer(std::string name, std::string id, int gamesWon, int points, bool isSubscribed);
	virtual ~UserPlayer();
	bool isAnOpponent();
	std::string toString();
};

