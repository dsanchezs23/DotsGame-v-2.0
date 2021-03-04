#pragma once
#include "AbstractField.h"

class ProcessedField{
private:
	int rows;
	int columns;
	int lastColumn;
	bool isEven(int number);
	void addPointToTheField(std::string** field, int toTheRow, int toTheColumn);
	//this methods are for for aesthetic
	void deleteSpaces(std::string** field);
	void deleteFakeSpaces(std::string** field);
public:
	ProcessedField();
	virtual ~ProcessedField();
	std::string** makeField(std::string** field, std::vector<AbstractField*> abstractFieldsVector, int rowsGameField, int columnsGameField);
};

