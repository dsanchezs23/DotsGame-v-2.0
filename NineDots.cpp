#include "NineDots.h"

NineDots::NineDots() {
	this->rows = 3;
	this->columns = 3;
	this->code = "nine";
}

NineDots::~NineDots(){
}

int NineDots::getRows() {
	return this->rows;
}

int NineDots::getColumns() {
	return this->columns;
}

std::string NineDots::getCode() {
	return this->code;
}
