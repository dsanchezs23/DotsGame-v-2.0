#include "FifteenDots.h"

FifteenDots::FifteenDots() {
	this->rows = 5;
	this->columns = 3;
	this->code = "fifteen";
}

FifteenDots::~FifteenDots() {
}

int FifteenDots::getRows() {
	return this->rows;
}

int FifteenDots::getColumns() {
	return this->columns;
}

std::string FifteenDots::getCode() {
	return this->code;
}