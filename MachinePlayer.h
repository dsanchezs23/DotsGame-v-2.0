#pragma once
#include "GenericPlayer.h"

class MachinePlayer : public GenericPlayer{
private:
	std::string id;
public:
	MachinePlayer();
	MachinePlayer(std::string id, int gamesWon, int points, bool isSubscribed);
	virtual ~MachinePlayer();
	std::string toString();
};

