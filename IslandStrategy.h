#pragma once
#include "Strategy.h"

class IslandStrategy : public Strategy{
private:
	Movement makeMovement(GameField*& gameField);
public:
	IslandStrategy();
	virtual ~IslandStrategy();
	std::string getName();
	bool executeStrategy(GameField*& gameField);
};

