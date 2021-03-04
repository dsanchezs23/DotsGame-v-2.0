#include "RandomStrategy.h"

RandomStrategy::RandomStrategy(){
}

RandomStrategy::~RandomStrategy(){
}

std::string RandomStrategy::getName(){
	return "Random strategy";
}

bool RandomStrategy::executeStrategy(GameField*& gameField){
 	Movement movement = checkPossibilityToMakeASquare(gameField);
	if (movement.getColumn() == 0 && movement.getRow() == 0) {
		makeMovement(gameField);
	}
	else {
		doLineHorOrVertRed(gameField, movement);
		return true;
	}
	return false;
}

void RandomStrategy::makeMovement(GameField*& gameField){
	executeRandomStrategy(gameField);
}
