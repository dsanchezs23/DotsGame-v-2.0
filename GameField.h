#pragma once
#include "AbstractField.h"
#include "ProcessedField.h"

class GameField : public AbstractField {
protected:
	std::string** field;
	std::vector<AbstractField*> abstractFieldsVector;
	int amountOfMovement;

	void setRowsAndColumns();
	void setRows();
public:
	GameField();
	virtual ~GameField();
	//--------------------------------------------
	void addAbstractField(AbstractField*);
	bool removeAbstractField(std::string); //recieve the field code
	//AbstractField getAbstractField(std::string)
	//---------------------------------------------
	void createField();
	bool makeMovement();
	void countMovements();
	int getAmountOfMovement();
	void addAmounOfMovement(int number);
	bool checkValidPosition(int row, int column);
	bool FieldsVectorIsEmpty();
	//--------------------------------------------
	int getRows();
	int getColumns();
	std::string getCode();
	std::string** getField();
	int isEven(int number);
	//--------------------------------------------
	std::string toString();
};

