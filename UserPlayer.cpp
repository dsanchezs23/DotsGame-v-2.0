#include "UserPlayer.h"

UserPlayer::UserPlayer(std::string name, std::string id) : GenericPlayer(name){
	this->id = id;
}

UserPlayer::UserPlayer(std::string name, std::string id, int gamesWon, int points, bool isSubscribed) : GenericPlayer(name, gamesWon, points, isSubscribed){
	this->id = id;
}

UserPlayer::~UserPlayer(){
}


std::string UserPlayer::toString(){
	std::stringstream x;

	x << "\nName: " << name;
	x << "\nPoints in this match: " << points;
	x << "\n";

	return x.str();
}

