#pragma once
#include <iostream>
#include "GameField.h"
#include "Movement.h"

class Strategy{
protected:
	int posRow;
	int posColumn;
	bool done;
	bool isEven(int number);
	void doLineHorOrVert(GameField*& gameField, Movement movement);
	void doLineHorOrVertBlue(GameField*& gameField, Movement movement);
	void doLineHorOrVertRed(GameField*& gameField, Movement movement);
	void executeRandomStrategy(GameField*& gameField); //this is to re-use code
public:
	Strategy();
	virtual ~Strategy();
	void setDone(bool done);
	bool isDone();
	//-------------------------------------
	virtual std::string getName() = 0;
	virtual bool executeStrategy(GameField*& gameField) = 0; //return true if a square is done
	Movement checkPossibilityToMakeASquare(GameField*& gameField);

};

