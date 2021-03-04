#include "GameField.h"

GameField::GameField(){
	this->field = nullptr;
	this->abstractFieldsVector = std::vector<AbstractField*>();
	this->amountOfMovement = 0;
}

GameField::~GameField(){
	for (int i = 0; i < this->rows; i++) {
		delete[] field[i];
	}
	delete[] field;

	for (int i = 0; i < this->abstractFieldsVector.size(); i++) {
		delete this->abstractFieldsVector.at(i);
	}
}

void GameField::addAbstractField(AbstractField* abstractField){
	this->abstractFieldsVector.push_back(abstractField);
}

bool GameField::removeAbstractField(std::string code){
	for (int i = this->abstractFieldsVector.size() - 1; i >= 0; i--) {
		if (this->abstractFieldsVector.at(i)->getCode() == code) {
			this->abstractFieldsVector.erase(this->abstractFieldsVector.begin() + i);
			return true;
		}
	}
	return false;
}

void GameField::createField(){
	setRowsAndColumns();
	ProcessedField processedField = ProcessedField();
	this->field = processedField.makeField(this->field, this->abstractFieldsVector, this->rows, this->columns);
	countMovements();
	//verify the matrix ant its spaces
}

void GameField::setRowsAndColumns(){
	this->columns = 0; // from abstractField
	for (int i = this->abstractFieldsVector.size() - 1; i >= 0; i--) {
		this->columns += this->abstractFieldsVector.at(i)->getColumns();
	}
	//this is to add spaces between each position, just for aesthetic
	this->columns = this->columns * 2 - 1;
	setRows();
}

void GameField::setRows(){
	this->rows = 0; // from abstractField
	for (int i = this->abstractFieldsVector.size() - 1; i >= 0; i--) {
		if (this->rows < this->abstractFieldsVector.at(i)->getRows()) {
			this->rows = this->abstractFieldsVector.at(i)->getRows();
		}
	}
	this->rows = this->rows * 2 - 1;
}

bool GameField::makeMovement(){
	return false;
}

void GameField::countMovements(){
	for (int i = 0; i < getRows(); i++) {
		for (int j = 0; j < getColumns(); j++) {
			if (this->field[i][j] == "  " || this->field[i][j] == " ") {
				if ((!isEven(i) && isEven(j)) || (isEven(i) && !isEven(j))) {
					if (checkValidPosition(i, j)) {
						this->amountOfMovement += 1;
					}
				}
			}
		}
	}
}

int GameField::getAmountOfMovement(){
	return this->amountOfMovement;
}

void GameField::addAmounOfMovement(int number){
	this->amountOfMovement += number;
}

bool GameField::checkValidPosition(int row, int column){
	if (isEven(row)) {
		if (this->field[row][column - 1] == "*" && this->field[row][column + 1] == "*") {
			return true;
		}
	}

	if (isEven(column)) {
		if (this->field[row - 1][column] == "*" && this->field[row + 1][column] == "*") {
			return true;
		}
	}
	return false;
}

bool GameField::FieldsVectorIsEmpty(){
	return this->abstractFieldsVector.size() == 0;
}

int GameField::getRows(){
	return this->rows;
}

int GameField::getColumns(){
	return this->columns;
}

std::string GameField::getCode(){
	return "GameField";
}

std::string** GameField::getField(){
	return field;
}

int GameField::isEven(int number){
	return (number == 0 || number % 2 == 0);
}

std::string GameField::toString(){
	std::stringstream x;
	x << "\n";
	x << "\n";
	for (int i = 0; i < this->rows; i++) {
		x << "\t";
		for (int j = 0; j < this->columns; j++) {
			x << field[i][j];
		}
		x << "\n";
	}

	return x.str();
}
