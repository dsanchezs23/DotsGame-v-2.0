#include "CloseStrategy.h"

CloseStrategy::CloseStrategy(){
}

CloseStrategy::~CloseStrategy(){
}

std::string CloseStrategy::getName(){
    return "Close strategy";
}

bool CloseStrategy::executeStrategy(GameField*& gameField){
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

Movement CloseStrategy::makeMovement(GameField*& gameField){
	Movement movement = Movement(0,0);
	std::string line = "";
	for (int i = 0; i < gameField->getRows(); i++) {
		for (int j = 0; j < gameField->getColumns(); j++) {
			line = "";
			if (!(isEven(i) && isEven(j))) { //if the both are even is a invalid position
				//checking the top side
				if (isEven(i)) { //is a vertical line
					line = "--";
					movement = checkVerticalLine(gameField, line, i, j);
					if (movement.getRow() != 0 && movement.getColumn() != 0) {
						return movement;
					}
				}
				if (isEven(j)) { //is a horizontal line
					line = "|";
					movement = checkHorizontalLine(gameField, line, i, j);
					if (movement.getRow() != 0 && movement.getColumn() != 0) {
						return movement;
					}
				}
			}
		}
	}

	return movement;
}

Movement CloseStrategy::checkVerticalLine(GameField*& gameField, std::string line, int i, int j){
	if (gameField->getField()[i][j] == "\x1B[36m" + line + "\033[0m") {//there's a user line
		if (i - 1 >= gameField->getRows() && j - 1 >= gameField->getColumns()) {//checking the left up side
			if (gameField->getField()[i - 1][j - 1] == " " || gameField->getField()[i - 1][j - 1] == "  ") {
				if (gameField->checkValidPosition(i - 1, j - 1)) {
					return Movement(i - 1, j - 1);
				}
			}
		}
		else if ((i - 1 >= gameField->getRows() && j + 1 < gameField->getColumns())) {//checking the right up side
			if (gameField->getField()[i - 1][j + 1] == " " || gameField->getField()[i - 1][j + 1] == "  ") {
				if (gameField->checkValidPosition(i - 1, j + 1)) {
					return Movement(i - 1, j + 1);
				}
			}
		}
		else if ((i + 1 < gameField->getRows() && j - 1 >= gameField->getColumns())) {//checking the left down side
			if (gameField->getField()[i + 1][j - 1] == " " || gameField->getField()[i + 1][j - 1] == "  ") {
				if (gameField->checkValidPosition(i + 1, j - 1)) {
					return Movement(i + 1, j - 1);
				}
			}
		}
		else if ((i + 1 < gameField->getRows() && j + 1 < gameField->getColumns())) {//checking the right down side
			if (gameField->getField()[i + 1][j + 1] == " " || gameField->getField()[i + 1][j + 1] == "  ") {
				if (gameField->checkValidPosition(i + 1, j + 1)) {
					return Movement(i + 1, j + 1);
				}
			}
		}
	}

	return Movement(0, 0);
}

Movement CloseStrategy::checkHorizontalLine(GameField*& gameField, std::string line, int i, int j){
	if (gameField->getField()[i][j] == "\x1B[36m" + line + "\033[0m") {//there's a user line
		if (i - 1 >= gameField->getRows() && j - 1 >= gameField->getColumns()) {//checking the left up side
			if (gameField->getField()[i - 1][j - 1] == " " || gameField->getField()[i - 1][j - 1] == "  ") {
				if (gameField->checkValidPosition(i - 1, j - 1)) {
					return Movement(i - 1, j - 1);
				}
			}
		}
		else if ((i - 1 >= gameField->getRows() && j + 1 < gameField->getColumns())) {//checking the right up side
			if (gameField->getField()[i - 1][j + 1] == " " || gameField->getField()[i - 1][j + 1] == "  ") {
				if (gameField->checkValidPosition(i - 1, j + 1)) {
					return Movement(i - 1, j + 1);
				}
			}
		}
		else if ((i + 1 < gameField->getRows() && j - 1 >= gameField->getColumns())) {//checking the left down side
			if (gameField->getField()[i + 1][j - 1] == " " || gameField->getField()[i + 1][j - 1] == "  ") {
				if (gameField->checkValidPosition(i + 1, j - 1)) {
					return Movement(i + 1, j - 1);
				}
			}
		}
		else if ((i + 1 < gameField->getRows() && j + 1 < gameField->getColumns())) {//checking the right down side
			if (gameField->getField()[i + 1][j + 1] == " " || gameField->getField()[i + 1][j + 1] == "  ") {
				if (gameField->checkValidPosition(i + 1, j + 1)) {
					return Movement(i + 1, j + 1);
				}
			}
		}
	}

	return Movement(0, 0);
}

