#pragma once
#include "Cell.h"
#include <iostream>
class Cell;

class GameField
{
private:
	static constexpr unsigned ROW = 3;
	static constexpr unsigned COLUMN = 3;
	Cell **field = setField(ROW, COLUMN);
	Cell** setField(int, int);
public:
	enum StateType { GAME, WIN_O, WIN_X, DRAW } StateT;
	GameField( StateType givenT = GAME );
	Cell** getField();
	StateType GameState();
	void turn();
	virtual ~GameField();
};

