#pragma once
#include "Strategy.h"

class CloseStrategy : public Strategy{
private:
	Movement makeMovement(GameField*& gameField);
	Movement checkVerticalLine(GameField*& gameField, std::string line, int i, int j);
	Movement checkHorizontalLine(GameField*& gameField, std::string line, int i, int j);
public:
	CloseStrategy();
	virtual ~CloseStrategy();
	std::string getName();
	bool executeStrategy(GameField*& gameField);
};

