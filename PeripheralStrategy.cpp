#include "PeripheralStrategy.h"

Movement PeripheralStrategy::makeMovement(GameField*& gameField){
	//checking the left side first
	for (int i = 0; i < gameField->getRows(); i++) {
		if (gameField->getField()[i][0] == " " || gameField->getField()[i][0] == "  ") {
			if (gameField->checkValidPosition(i, 0)) {
				return Movement(i, 0);
			}
		}
	}
	//checking the right side
	for (int i = 0; i < gameField->getRows(); i++) {
		if (gameField->getField()[i][gameField->getColumns() - 1] == " " || gameField->getField()[i][gameField->getColumns() - 1] == "  ") {
			if (gameField->checkValidPosition(i, gameField->getColumns() - 1)) {
				return Movement(i, gameField->getColumns() - 1);
			}
		}
	}
	//checking the top side
	for (int i = 0; i < gameField->getColumns(); i++) {
		if (gameField->getField()[0][i] == " " || gameField->getField()[0][i] == "  ") {
			if (gameField->checkValidPosition(0, i)) {
				return Movement(0, i);
			}
		}
	}
	//checking the bottom side
	for (int i = 0; i < gameField->getColumns(); i++) {
		if (gameField->getField()[gameField->getRows() - 1][i] == " " || gameField->getField()[gameField->getRows() - 1][i] == "  ") {
			if (gameField->checkValidPosition(gameField->getRows() - 1, i)) {
				return Movement(gameField->getRows() - 1, i);
			}
		}
	}

    return Movement(0, 0);
}

PeripheralStrategy::PeripheralStrategy(){
}

PeripheralStrategy::~PeripheralStrategy(){
}

std::string PeripheralStrategy::getName(){
    return "Peripheral strategy";
}

bool PeripheralStrategy::executeStrategy(GameField*& gameField){
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
