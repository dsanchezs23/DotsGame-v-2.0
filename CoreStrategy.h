#pragma once
#include "Strategy.h"

class CoreStrategy : public Strategy{
private:
	Movement makeMovement(GameField*& gameField);
public:
	CoreStrategy();
	virtual ~CoreStrategy();
	std::string getName();
	bool executeStrategy(GameField*& gameField);
};

