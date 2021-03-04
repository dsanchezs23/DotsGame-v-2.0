#include "GenericPlayer.h"

void GenericPlayer::restartGamesWon(){
	this->gamesWon = 0;
}

void GenericPlayer::restartPoints(){
	this->points = 0;
}

void GenericPlayer::unsubscribePlayer(){
	this->isSubscribed = false;
}

GenericPlayer::GenericPlayer(std::string name){
	this->name = name;
	this->gamesWon = 0;
	this->points = 0;
	this->isSubscribed = false;
	this->strategy = nullptr;
}

GenericPlayer::GenericPlayer(std::string name, int gamesWon, int points, bool isSubscribed){
	this->name = name;
	this->gamesWon = gamesWon;
	this->points = points;
	this->isSubscribed = isSubscribed;
	this->strategy = nullptr;
}

GenericPlayer::~GenericPlayer(){
	delete strategy;
}

void GenericPlayer::addGameWon(){
	this->gamesWon += 1;
}

void GenericPlayer::addPoint(){
	this->points += 1;
}

void GenericPlayer::subscribePlayer(){
	this->isSubscribed = true;
}

std::string GenericPlayer::getName(){
	return this->name;
}

int GenericPlayer::getGamesWon(){
	return this->gamesWon;
}

int GenericPlayer::getPoints(){
	return this->points;
}

bool GenericPlayer::getSubscriptionStatus(){
	return this->isSubscribed;
}

void GenericPlayer::restartPlayerSettings(){
	restartGamesWon();
	restartPoints();
	unsubscribePlayer();
}

void GenericPlayer::play(GameField*& gameField, GenericPlayer*& player){
	if (this->strategy->executeStrategy(gameField)) {
		player->addPoint();
	}
}

void GenericPlayer::setStrategy(Strategy* strategy){
	this->strategy = strategy;
}

void GenericPlayer::setMoveDone(bool MoveDone){
	this->strategy->setDone(MoveDone);
}

bool GenericPlayer::isMoveDone(){
	return this->strategy->isDone();
}

std::string GenericPlayer::toString(){
	std::stringstream x;

	x << "\nName: " << name;
	x << "\nPoints in this match: " << points;
	x << "\nGames won: " << gamesWon;

	return x.str();
}
