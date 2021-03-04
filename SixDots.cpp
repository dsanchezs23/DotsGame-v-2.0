#include "SixDots.h"

SixDots::SixDots() {
	this->rows = 3;
	this->columns = 2;
	this->code = "six";
}

SixDots::~SixDots() {
}

int SixDots::getRows() {
	return this->rows;
}

int SixDots::getColumns() {
	return this->columns;
}

std::string SixDots::getCode() {
	return this->code;
}
