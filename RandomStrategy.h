#pragma once
#include "Strategy.h"

class RandomStrategy : public Strategy{
private:
	void makeMovement(GameField*& gameField);
public:
	RandomStrategy();
	virtual ~RandomStrategy();
	std::string getName();
	bool executeStrategy(GameField*& gameField);
};

