#include "MachinePlayer.h"

MachinePlayer::MachinePlayer() : GenericPlayer("Machine", 0, 0, true){
	this->id = "000000000";
}

MachinePlayer::MachinePlayer(std::string id, int gamesWon, int points, bool isSubscribed) : GenericPlayer("Machine", 0, 0, true) {
	this->id = id;
}

MachinePlayer::~MachinePlayer(){
}

std::string MachinePlayer::toString(){
	std::stringstream x;

	x << "\nName: " << name;
	x << "\nPoints in this match: " << points;
	x << "\n";

	return x.str();
}
