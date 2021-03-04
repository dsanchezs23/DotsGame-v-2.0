#include "CoreStrategy.h"

Movement CoreStrategy::makeMovement(GameField*& gameField){
	this->posRow = gameField->getRows() / 2;
	this->posColumn = gameField->getColumns() / 2;
	
	if (gameField->getField()[this->posRow][this->posColumn] == " " || gameField->getField()[this->posRow][this->posColumn] == "  ") {
		if (gameField->checkValidPosition(this->posRow, this->posColumn)) {
			return Movement(this->posRow, this->posColumn);
		}
		else {
			if (gameField->getField()[this->posRow - 1][this->posColumn - 1] == " " || gameField->getField()[this->posRow - 1][this->posColumn - 1] == "  ") {
				if (gameField->checkValidPosition(this->posRow - 1, this->posColumn - 1)) {
					return Movement(this->posRow - 1, this->posColumn - 1);
				}
				else {
					if (gameField->getField()[this->posRow + 1][this->posColumn + 1] == " " || gameField->getField()[this->posRow + 1][this->posColumn + 1] == "  ") {
						if (gameField->checkValidPosition(this->posRow + 1, this->posColumn + 1)) {
							return Movement(this->posRow + 1, this->posColumn + 1);
						}
					}
				}
			}
		}
	}
    return Movement(0,0);
}

CoreStrategy::CoreStrategy(){
}

CoreStrategy::~CoreStrategy(){
}

std::string CoreStrategy::getName(){
    return "Core strategy";
}

bool CoreStrategy::executeStrategy(GameField*& gameField){
	Movement movement = checkPossibilityToMakeASquare(gameField);
	if (movement.getColumn() == 0 && movement.getRow() == 0) {
		movement = makeMovement(gameField);
		if (movement.getColumn() == 0 && movement.getRow() == 0) {
			executeRandomStrategy(gameField);
		}
		else {
			doLineHorOrVertRed(gameField, movement);
		}
	}
	else {
		doLineHorOrVertRed(gameField, movement);
		return true;
	}
	return false;
}
