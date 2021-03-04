#include "IslandStrategy.h"

Movement IslandStrategy::makeMovement(GameField*& gameField){
	short int lines = 0;
	for (int i = 0; i < gameField->getRows(); i++) {
		for (int j = 0; j < gameField->getColumns(); j++) {
			if ((!(isEven(i)) && isEven(j)) || (isEven(i) && (!isEven(j)))) { //if the both are even is a invalid position
				lines = 0;
				//checking the top side
				if (gameField->getField()[i][j] == "  " || gameField->getField()[i][j] == " ") {
					if (gameField->checkValidPosition(i, j)) {
						lines += 1;
						this->posRow = i;
						this->posColumn = j;
					}
					else {
						lines = 0;
					}
				}
				else {
					lines = 0;
				}
				//checking the left side
				if (i + 1 < gameField->getRows()) {
					if (gameField->getField()[i + 1][j - 1] == "  " || gameField->getField()[i + 1][j - 1] == " ") {
						if (gameField->checkValidPosition(i + 1, j - 1)) {
							lines += 1;
							this->posRow = i + 1;
							this->posColumn = j - 1;
						}
						else {
							lines = 0;
						}
					}
					else {
						lines = 0;
					}
				}
				//checking the right side
				if (i + 1 < gameField->getRows() && j + 1 < gameField->getColumns()) {
					if (gameField->getField()[i + 1][j + 1] == "  " || gameField->getField()[i + 1][j + 1] == " ") {
						if (gameField->checkValidPosition(i + 1, j + 1)) {
							lines += 1;
							this->posRow = i + 1;
							this->posColumn = j + 1;
						}
						else {
							lines = 0;
						}
					}
					else {
						lines = 0;
					}
				}
				//checking the bottom side
				if (i + 2 < gameField->getRows()) {
					if (gameField->getField()[i + 2][j] == "  " || gameField->getField()[i + 2][j] == " ") {
						if (gameField->checkValidPosition(i + 2, j)) {
							lines += 1;
							this->posRow = i + 2;
							this->posColumn = j;
						}
						else {
							lines = 0;
						}
					}
					else {
						lines = 0;
					}
				}
				if (lines == 3) {//if is equal to 2, leave the possible to make a square for the user
					return Movement(this->posRow, this->posColumn);
				}
			}
		}
	}
	return Movement(0, 0);
}

IslandStrategy::IslandStrategy(){
}

IslandStrategy::~IslandStrategy(){
}

std::string IslandStrategy::getName(){
    return "Island strategy";
}

bool IslandStrategy::executeStrategy(GameField*& gameField){
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
