#include "Strategy.h"

bool Strategy::isEven(int number){
	return (number == 0 || number % 2 == 0);
}

void Strategy::doLineHorOrVert(GameField*& gameField, Movement movement){
	if (isEven(movement.getRow()) && !isEven(movement.getColumn())) {
		//is horizontal --
		gameField->getField()[movement.getRow()][movement.getColumn()] = "--";
	}
	else if (!isEven(movement.getRow()) && isEven(movement.getColumn())) {
		//is vertical |
		gameField->getField()[movement.getRow()][movement.getColumn()] = "|";
	}
	else {
		std::cout << "There is an error";
	}
}

void Strategy::doLineHorOrVertBlue(GameField*& gameField, Movement movement){
	std::string line = "";
	if (isEven(movement.getRow()) && !isEven(movement.getColumn())) {
		//is horizontal --
		line = "--";
		gameField->getField()[movement.getRow()][movement.getColumn()] = "\x1B[36m" + line + "\033[0m";
	}
	else if (!isEven(movement.getRow()) && isEven(movement.getColumn())) {
		//is vertical |
		line = "|";
		gameField->getField()[movement.getRow()][movement.getColumn()] = "\x1B[36m" + line + "\033[0m";
	}
	else {
		std::cout << "There is an error";
	}
}

void Strategy::doLineHorOrVertRed(GameField*& gameField, Movement movement){
	std::string line = "";
	if (isEven(movement.getRow()) && !isEven(movement.getColumn())) {
		//is horizontal --
		line = "--";
		gameField->getField()[movement.getRow()][movement.getColumn()] = "\x1B[31m" + line + "\033[0m";
	}
	else if (!isEven(movement.getRow()) && isEven(movement.getColumn())) {
		//is vertical |
		line = "|";
		gameField->getField()[movement.getRow()][movement.getColumn()] = "\x1B[31m" + line + "\033[0m";
	}
	else {
		std::cout << "There is an error";
	}
}

void Strategy::executeRandomStrategy(GameField*& gameField){
	for (int i = 0; i < gameField->getRows(); i++) {
		for (int j = 0; j < gameField->getColumns(); j++) {
			if (!(isEven(i) && isEven(j))) { //if the both are even is a invalid position
				//checking the top side
				if (gameField->getField()[i][j] == " " || gameField->getField()[i][j] == "  ") {
					if (gameField->checkValidPosition(i, j)) {
						doLineHorOrVertRed(gameField, Movement(i, j));
						return;
					}
				}
				//checking the left side
				if (i + 1 < gameField->getRows()) {
					if (gameField->getField()[i + 1][j - 1] == " " || gameField->getField()[i][j] == " ") {
						if (gameField->checkValidPosition(i + 1, j - 1)) {
							doLineHorOrVertRed(gameField, Movement(i + 1, j - 1));
							return;
						}
					}
				}
				//checking the right side
				if (i + 1 < gameField->getRows() && j + 1 < gameField->getColumns()) {
					if (gameField->getField()[i + 1][j + 1] == " " || gameField->getField()[i][j] == " ") {
						if (gameField->checkValidPosition(i + 1, j + 1)) {
							doLineHorOrVertRed(gameField, Movement(i + 1, j + 1));
							return;
						}
					}
				}
				//checking the bottom side
				if (i + 2 < gameField->getRows()) {
					if (gameField->getField()[i + 2][j] == " " || gameField->getField()[i][j] == " ") {
						if (gameField->checkValidPosition(i + 2, j)) {
							doLineHorOrVertRed(gameField, Movement(i + 2, j));
							return;
						}
					}
				}
			}
		}
	}
}

Strategy::Strategy(){
	this->posRow = 0;
	this->posColumn = 0;
	this->done = false;
}

Strategy::~Strategy(){
}

void Strategy::setDone(bool done){
	this->done = done;
}

bool Strategy::isDone(){
	return this->done;
}

Movement Strategy::checkPossibilityToMakeASquare(GameField*& gameField) {
	short int lines = 0;
	std::string line = "";
	for (int i = 0; i < gameField->getRows(); i++) {
		for (int j = 0; j < gameField->getColumns(); j++) {
			if ((!(isEven(i)) && isEven(j)) || (isEven(i) && (!isEven(j)))) { //if the both are even is a invalid position
				lines = 0;
				//checking the top side
				line = "--";
				if (!(gameField->getField()[i][j] == "\x1B[36m" + line + "\033[0m" || gameField->getField()[i][j] == "\x1B[31m" + line + "\033[0m")) {
					if (gameField->checkValidPosition(i, j)) {
						lines += 1;
						this->posRow = i;
						this->posColumn = j;
					}
					else {
						lines = 4;
					}
				}
				//checking the left side
				if (i + 1 < gameField->getRows()) {
					line = "|";
					if (!(gameField->getField()[i + 1][j - 1] == "\x1B[36m" + line + "\033[0m" || gameField->getField()[i + 1][j - 1] == "\x1B[31m" + line + "\033[0m")) {
						if (gameField->checkValidPosition(i + 1, j - 1)) {
							lines += 1;
							this->posRow = i + 1;
							this->posColumn = j - 1;
						}
						else {
							lines = 4;
						}
					}
				}
				else {
					lines = 4;
				}
				//checking the right side
				if (i + 1 < gameField->getRows() && j + 1 < gameField->getColumns()) {
					line = "|";
					if (!(gameField->getField()[i + 1][j + 1] == "\x1B[36m" + line + "\033[0m" || gameField->getField()[i + 1][j + 1] == "\x1B[31m" + line + "\033[0m")) {
						if (gameField->checkValidPosition(i + 1, j + 1)) {
							lines += 1;
							this->posRow = i + 1;
							this->posColumn = j + 1;
						}
						else {
							lines = 4;
						}
					}
				}
				else {
					lines = 4;
				}
				//checking the bottom side
				if (i + 2 < gameField->getRows()) {
					line = "--";
					if (!(gameField->getField()[i + 2][j] == "\x1B[36m" + line + "\033[0m" || gameField->getField()[i + 2][j] == "\x1B[31m" + line + "\033[0m")) {
						if (gameField->checkValidPosition(i + 2, j)) {
							lines += 1;
							this->posRow = i + 2;
							this->posColumn = j;
						}
						else {
							lines = 4;
						}
					}
				}
				else {
					lines = 4;
				}

				if (lines == 1) {//there is a possible to make a square
					return Movement(this->posRow, this->posColumn);
				}
			}
		}
	}
	return Movement(0, 0);
}
