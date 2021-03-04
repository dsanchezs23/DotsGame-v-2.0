#pragma once
#include "Strategy.h"

class PeripheralStrategy : public Strategy{
private:
	Movement makeMovement(GameField*& gameField);
public:
	PeripheralStrategy();
	virtual ~PeripheralStrategy();
	std::string getName();
	bool executeStrategy(GameField*& gameField);
};

