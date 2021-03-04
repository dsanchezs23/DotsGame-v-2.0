#include "ProcessedField.h"

bool ProcessedField::isEven(int number) {
	return (number == 0 || number % 2 == 0);
}

void ProcessedField::addPointToTheField(std::string** field, int toTheRow, int toTheColumn){
	for (int i = 0; i < toTheRow; i++) {
		for (int j = this->lastColumn; j < this->lastColumn + toTheColumn; j++) {
			if (isEven(i) && isEven(j)) {
				field[i][j] = "*";
			}
		}
	}
}

void ProcessedField::deleteSpaces(std::string** field){
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			if (isEven(i) && isEven(j)) {
				field[i][j] = " ";
			}
			if (!isEven(i) && !isEven(j)) {
				field[i][j] = "  ";
			}
		}
	}
}

void ProcessedField::deleteFakeSpaces(std::string** field){
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			if (isEven(i) && isEven(j) && field[i][j] == "  ") {
				if (field[0][j] == "*") {
					field[i][j] = " ";
				}
			}

			if (!isEven(i) && isEven(j) && field[i][j] == "  ") {
				if (field[0][j] == "*") {
					field[i][j] = " ";
				}
			}
		}
	}
}

ProcessedField::ProcessedField(){
	this->rows = 0;
	this->columns = 0;
	this->lastColumn = 0;
}

ProcessedField::~ProcessedField(){
}

std::string** ProcessedField::makeField(std::string** field, std::vector<AbstractField*> abstractFieldsVector, int rowsGameField, int columnsGameField){
	int iterator = 0;
	this->rows = rowsGameField;
	this->columns = columnsGameField;
	field = new std::string * [this->rows];
	this->lastColumn = 0;

	for (int i = 0; i < this->rows; i++) {
		field[i] = new std::string[this->columns];
	}

	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			field[i][j] = "  ";
		}
	}

	deleteSpaces(field);

	while (iterator < abstractFieldsVector.size()) {
		if (abstractFieldsVector.at(iterator)->getCode() == "six") {
			addPointToTheField(field, 5, 3);
			//this is to avoid problems adding the '*'
			this->lastColumn += 4;
		}
		else if (abstractFieldsVector.at(iterator)->getCode() == "nine") {
			addPointToTheField(field, 5, 5);
			//this is to avoid problems adding the '*'
			this->lastColumn += 6;
		}
		else if (abstractFieldsVector.at(iterator)->getCode() == "fifteen") {
			addPointToTheField(field, 9, 5);
			//this is to avoid problems adding the '*'
			this->lastColumn += 6;
		}
		iterator++;
	}
	deleteFakeSpaces(field);
	return field;
}
