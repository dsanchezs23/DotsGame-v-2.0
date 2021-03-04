#pragma once
#include "AbstractField.h"

class SixDots : public AbstractField {
public:
	SixDots();
	virtual ~SixDots();
	int getRows();
	int getColumns();
	std::string getCode();
};

