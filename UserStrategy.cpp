#include "UserStrategy.h"

void UserStrategy::putOnTheNextPosition(GameField*& gameField){
    for (int i = 0; i < gameField->getRows(); i++) {
        for (int j = 0; j < gameField->getColumns(); j++) {
            if (gameField->getField()[i][j] == "  " || gameField->getField()[i][j] == " ") {
				if ((!isEven(i) && isEven(j)) || (isEven(i) && !isEven(j))) {
					if (gameField->checkValidPosition(i, j)){
						this->currentRow = i;
						this->currentColumn = j;
						this->lastSymbol = gameField->getField()[this->currentRow][this->currentColumn];
						doLineHorOrVert(gameField, Movement(i, j));
						return;
					}
				}
			}
		}
	}
}

void UserStrategy::moveOnTheField(GameField*& gameField) {
	int first = _getch();
	int option = _getch();
	if (option == 72) {// up
		if (verifyMovement(gameField, this->currentRow - 2, this->currentColumn)) {
			deleteLastMovement(gameField);
			this->currentRow = this->currentRow - 2;
			//this->currentColumn = this->currentColumn;
			this->lastSymbol = gameField->getField()[this->currentRow][this->currentColumn];
			doLineHorOrVert(gameField, Movement(this->currentRow, this->currentColumn));
		}
	}
	else if (option == 80) {//down
		if (verifyMovement(gameField, this->currentRow + 2, this->currentColumn)) {
			deleteLastMovement(gameField);
			this->currentRow = this->currentRow + 2;
			//this->currentColumn = this->currentColumn;
			this->lastSymbol = gameField->getField()[this->currentRow][this->currentColumn];
			doLineHorOrVert(gameField, Movement(this->currentRow, this->currentColumn));
		}
	}
	else if (option == 77) {//right
		if (verifyMovement(gameField, this->currentRow + 1, this->currentColumn + 1)) {
			deleteLastMovement(gameField);
			this->currentRow = this->currentRow + 1;
			this->currentColumn = this->currentColumn + 1;
			this->lastSymbol = gameField->getField()[this->currentRow][this->currentColumn];
			doLineHorOrVert(gameField, Movement(this->currentRow, this->currentColumn));
		}
	}
	else if (option == 75) {//left
		if (verifyMovement(gameField, this->currentRow + 1, this->currentColumn - 1)) {
			deleteLastMovement(gameField);
			this->currentRow = this->currentRow + 1;
			this->currentColumn = this->currentColumn - 1;
			this->lastSymbol = gameField->getField()[this->currentRow][this->currentColumn];
			doLineHorOrVert(gameField, Movement(this->currentRow, this->currentColumn));
		}
	}
	else if (option == 32) {
		deleteLastMovement(gameField);
		if (gameField->getField()[this->currentRow][this->currentColumn] == " " || gameField->getField()[this->currentRow][this->currentColumn] == "  ") {
			if (this->isOpponent) {
				doLineHorOrVertRed(gameField, Movement(this->currentRow, this->currentColumn));
			}
			else {
				doLineHorOrVertBlue(gameField, Movement(this->currentRow, this->currentColumn));
			}
			this->lastSymbol = "";
			this->firsTime = true;
			this->done = true;
			verifySquare(gameField);
		}
	}
}

bool UserStrategy::verifyMovement(GameField*& gameField, int row, int column) {
	if (row < 0 || column < 0) {
		return false;
	}
	else if ((row > gameField->getRows() || column > gameField->getColumns())) {
		return false;
	}
	else if (gameField->getField()[row][column] == "  " || gameField->getField()[row][column] == " ") {
		if (gameField->checkValidPosition(row, column)) {
			return true;
		}
		return false;
	}
	else {
		return true;
	}
}

void UserStrategy::deleteLastMovement(GameField*& gameField) {
	if (this->lastSymbol == "") {
		return;
	}
	else {
		gameField->getField()[this->currentRow][this->currentColumn] = lastSymbol;
	}
}

UserStrategy::UserStrategy() {
	this->currentRow = 0;
	this->currentColumn = 0;
	this->lastSymbol = "";
	this->firsTime = true;
	this->squareDone = false;
	this->isOpponent = false;
}

UserStrategy::UserStrategy(bool isOpponent){
	this->currentRow = 0;
	this->currentColumn = 0;
	this->lastSymbol = "";
	this->firsTime = true;
	this->squareDone = false;
	this->isOpponent = true;
}

void UserStrategy::verifySquare(GameField*& gameField) {
	std::string line = "";
	int lines = 0;
	if (isEven(this->currentRow)) {//is a horizontal line
		//checking the upper side
		if (this->currentRow - 1 >= 0 && this->currentColumn - 1 >= 0) {//is a valid position
			//checking the left top side
			line = "|";
			if (gameField->getField()[this->currentRow - 1][this->currentColumn - 1] == "\x1B[36m" + line + "\033[0m" || gameField->getField()[this->currentRow - 1][this->currentColumn - 1] == "\x1B[31m" + line + "\033[0m") {
				lines += 1;
			}
			//checking the top side
			if (this->currentRow - 2 >= 0) {//is a valid position
				line = "--";
				if (gameField->getField()[this->currentRow - 2][this->currentColumn] == "\x1B[36m" + line + "\033[0m" || gameField->getField()[this->currentRow - 2][this->currentColumn] == "\x1B[31m" + line + "\033[0m") {
					lines += 1;
				}
			}
			//checking the right top side
			if (this->currentColumn + 1 < gameField->getColumns()) {//is a valid position
				line = "|";
				if (gameField->getField()[this->currentRow - 1][this->currentColumn + 1] == "\x1B[36m" + line + "\033[0m" || gameField->getField()[this->currentRow - 1][this->currentColumn + 1] == "\x1B[31m" + line + "\033[0m") {
					lines += 1;
				}
			}
		}
		if (lines == 3) {
			this->squareDone = true;
			return;
		}
		lines = 0;
		//checking the bottom side
		if (this->currentRow + 1 < gameField->getRows() && this->currentColumn - 1 >= 0) {//is a valid position
			//checking the left bottom side
			line = "|";
			if (gameField->getField()[this->currentRow + 1][this->currentColumn - 1] == "\x1B[36m" + line + "\033[0m" || gameField->getField()[this->currentRow + 1][this->currentColumn - 1] == "\x1B[31m" + line + "\033[0m") {
				lines += 1;
			}
			//checking the bottom side
			if (this->currentRow + 2 < gameField->getRows()) {//is a valid position
				line = "--";
				if (gameField->getField()[this->currentRow + 2][this->currentColumn] == "\x1B[36m" + line + "\033[0m" || gameField->getField()[this->currentRow + 2][this->currentColumn] == "\x1B[31m" + line + "\033[0m") {
					lines += 1;
				}
			}
			//checking the right bottom side
			if (this->currentRow + 1 < gameField->getColumns() && this->currentColumn + 1 < gameField->getColumns()) {//is a valid position
				line = "|";
				if (gameField->getField()[this->currentRow + 1][this->currentColumn + 1] == "\x1B[36m" + line + "\033[0m" || gameField->getField()[this->currentRow + 1][this->currentColumn + 1] == "\x1B[31m" + line + "\033[0m") {
					lines += 1;
				}
			}
		}
		if (lines == 3) {
			this->squareDone = true;
			return;
		}
		lines = 0;
	}
	if (isEven(this->currentColumn)) {//is a vertical line
		//checking the top left side
		if (this->currentRow - 1 >= 0 && this->currentColumn - 1 >= 0) {//is a valid position
			//checking the left top side
			line = "--";
			if (gameField->getField()[this->currentRow - 1][this->currentColumn - 1] == "\x1B[36m" + line + "\033[0m" || gameField->getField()[this->currentRow - 1][this->currentColumn - 1] == "\x1B[31m" + line + "\033[0m") {
				lines += 1;
			}
			//checking the left side
			if (this->currentColumn - 2 >= 0) {//is a valid position
				line = "|";
				if (gameField->getField()[this->currentRow][this->currentColumn - 2] == "\x1B[36m" + line + "\033[0m" || gameField->getField()[this->currentRow][this->currentColumn - 2] == "\x1B[31m" + line + "\033[0m") {
					lines += 1;
				}
			}
			//checking the bottom left side
			if (this->currentRow + 1 < gameField->getRows()) {//is a valid position
				line = "--";
				if (gameField->getField()[this->currentRow + 1][this->currentColumn - 1] == "\x1B[36m" + line + "\033[0m" || gameField->getField()[this->currentRow + 1][this->currentColumn - 1] == "\x1B[31m" + line + "\033[0m") {
					lines += 1;
				}
			}
		}
		if (lines == 3) {
			this->squareDone = true;
			return;
		}
		lines = 0;
		//checking the right side
		if (this->currentRow - 1 >= 0 && this->currentColumn + 1 < gameField->getColumns()) {//is a valid position
			//checking the top right side
			line = "--";
			if (gameField->getField()[this->currentRow - 1][this->currentColumn + 1] == "\x1B[36m" + line + "\033[0m" || gameField->getField()[this->currentRow - 1][this->currentColumn + 1] == "\x1B[31m" + line + "\033[0m") {
				lines += 1;
			}
			//checking the right side
			if (this->currentColumn + 2 < gameField->getColumns()) {//is a valid position
				line = "|";
				if (gameField->getField()[this->currentRow][this->currentColumn + 2] == "\x1B[36m" + line + "\033[0m" || gameField->getField()[this->currentRow][this->currentColumn + 2] == "\x1B[31m" + line + "\033[0m") {
					lines += 1;
				}
			}
			//checking the right bottom side
			if (this->currentRow + 1 < gameField->getColumns() && this->currentColumn + 1 < gameField->getColumns()) {//is a valid position
				line = "--";
				if (gameField->getField()[this->currentRow + 1][this->currentColumn + 1] == "\x1B[36m" + line + "\033[0m" || gameField->getField()[this->currentRow + 1][this->currentColumn + 1] == "\x1B[31m" + line + "\033[0m") {
					lines += 1;
				}
			}
		}
		if (lines == 3) {
			this->squareDone = true;
			return;
		}
		lines = 0;
	}
}

UserStrategy::~UserStrategy(){
}

std::string UserStrategy::getName(){
    return "Your own strategy";
}

bool UserStrategy::executeStrategy(GameField*& gameField){
	this->squareDone = false;
	if (this->firsTime) {
		putOnTheNextPosition(gameField);
		this->firsTime = false;
	}
	else {
		moveOnTheField(gameField);
	}

	return this->squareDone;
}
