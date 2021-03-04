#pragma once
#include "AbstractField.h"

class FifteenDots : public AbstractField {
public:
	FifteenDots();
	virtual ~FifteenDots();
	int getRows();
	int getColumns();
	std::string getCode();
};

