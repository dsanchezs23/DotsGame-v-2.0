#pragma once
#include "AbstractField.h"

class NineDots : public AbstractField {
public:
	NineDots();
	virtual ~NineDots();
	int getRows();
	int getColumns();
	std::string getCode();
};

