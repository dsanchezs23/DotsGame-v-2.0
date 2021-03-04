#pragma once
#include <Windows.h>
#include "GameField.h"
#include "SixDots.h"
#include "NineDots.h"
#include "FifteenDots.h"
#include "MachinePlayer.h"
#include "UserPlayer.h"

class View{
public:
	static void buildingField(GameField*& gameField);
	static void menuForBuildingField(GameField*& gameField);
	static GenericPlayer* chooseTheOpponent();
	static Strategy* chooseStrategy();
	static void showFieldAndPoints(GameField*& gameField, GenericPlayer*& user, GenericPlayer*& opponent);
	static UserPlayer* createUserPlayer();
	static void gameOver(GenericPlayer*& user, GenericPlayer*& opponent);
};

