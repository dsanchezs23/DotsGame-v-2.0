#pragma once
#include "CloseStrategy.h"
#include "CoreStrategy.h"
#include "IslandStrategy.h"
#include "PeripheralStrategy.h"
#include "RandomStrategy.h"
#include "UserStrategy.h"
#include <iostream>
#include <sstream>

class GenericPlayer{
protected:
	std::string name;
	int gamesWon;
	int points;
	bool isSubscribed;
	Strategy* strategy;
	//------------------------//
	void restartGamesWon();
	void restartPoints();
	void unsubscribePlayer();
public:
	GenericPlayer(std::string name);
	GenericPlayer(std::string name, int gamesWon, int points, bool isSubscribed);
	virtual ~GenericPlayer();
	void addGameWon(); // doesn't need a pharameter because the games are adding one by one
	void addPoint(); // doesn't need a pharameter because the points are adding one by one
	void subscribePlayer();
	std::string getName();
	int getGamesWon();
	int getPoints();
	bool getSubscriptionStatus();
	void restartPlayerSettings();
	void play(GameField*& gameField, GenericPlayer*& player);
	void setStrategy(Strategy* strategy);
	void setMoveDone(bool MoveDone);
	bool isMoveDone();
	virtual std::string toString();
};

