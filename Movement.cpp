#include "Movement.h"

Movement::Movement(int row, int column){
	this->row = row;
	this->column = column;
}

Movement::~Movement(){
}

int Movement::getRow(){
	return this->row;
}

int Movement::getColumn(){
	return column;
}
