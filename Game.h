#pragma once
#include "View.h"

class Game{
private:
	GameField* gameField;
	GenericPlayer* user;
	GenericPlayer* opponent;
	bool isGameOver();
	bool isSquareMade();
	bool thereIsAvailableSpaces();
	void play();
	void chooseStrategy();
	void chooseTheOpponent();
	void vsMachine();
	void vsPlayer();
public:
	Game();
	virtual	~Game();
	void start();
	void buildTheField();
};

