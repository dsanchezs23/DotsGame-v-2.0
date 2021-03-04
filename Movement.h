#pragma once

class Movement{
private:
	int row;
	int column;
public:
	Movement(int row, int column);
	virtual ~Movement();
	int getRow();
	int getColumn();
};

