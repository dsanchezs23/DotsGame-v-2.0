#pragma once
#include "UserPlayer.h"
#include "GameField.h"
#include <iostream>

//this class is to load the data
class Files{
public:
	static UserPlayer* readUser(std::istream& handle);
	static GameField* readField(std::istream&);
};

