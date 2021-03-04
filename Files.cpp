#include "Files.h"

UserPlayer* Files::readUser(std::istream& handle){
	std::string id, name = "";
	int gamesWon, points = 0;
	bool isSubscribed;
	handle.clear();
	handle.ignore(255, '\n');
	std::getline(handle, id);
	std::getline(handle, name);
	handle >> gamesWon;
	handle >> points;
	handle >> isSubscribed;

	return new UserPlayer(name, id, gamesWon, points, isSubscribed);
}
