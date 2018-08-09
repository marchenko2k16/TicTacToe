#pragma once
class Cell
{
public:
	enum CellType { EMPTY, X, O } CellT;
	Cell( CellType type = EMPTY );
};

