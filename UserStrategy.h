#pragma once
#include "Strategy.h"
#include <conio.h>

class UserStrategy : public Strategy{
private:
	int currentRow;
	int currentColumn;
	int squareDone;
	std::string lastSymbol;
	bool firsTime;
	bool isOpponent;
	void putOnTheNextPosition(GameField*& gameField);
	void moveOnTheField(GameField*& gameField);
	bool verifyMovement(GameField*& gameField, int row, int column);
	void deleteLastMovement(GameField*& gameField);
	void verifySquare(GameField*& gameField);
public:
	UserStrategy();
	UserStrategy(bool isOpponent);
	virtual ~UserStrategy();
	std::string getName();
	bool executeStrategy(GameField*& gameField);
};

