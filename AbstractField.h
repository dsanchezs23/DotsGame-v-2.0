#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class AbstractField{
protected:
	int rows;
	int columns;
	std::string code;
public:
	AbstractField();
	virtual ~AbstractField();
	//--------------------------------
	virtual int getRows() = 0;
	virtual int getColumns() = 0;
	virtual std::string getCode() = 0;
};