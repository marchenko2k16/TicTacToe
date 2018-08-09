#include "GameField.h"

Cell ** GameField::setField(int r, int c)
{
	field = new Cell*[c];
	for (int i = 0; i < r; i++)
	{
		field[i] = new Cell[c];
	}
	return field;
}

Cell** GameField::getField()
{
	return field;
}



GameField::StateType GameField::GameState()
{
	for (int i = 0; i < 3; i++)
	{
		if ( field[i][0].CellT == field[i][1].CellT == field[i][2].CellT )
		{
			if ( Cell::CellType::X == field[i][1].CellT )
			{
				std::cout << "win_x" << std::endl;
				return WIN_X;
			}
			if ( Cell::CellType::O == field[i][1].CellT )
			{ 
				std::cout << "win_o" << std::endl;
				return WIN_O;
			}
		}
	}
	
	for (int j = 0; j < 3; j++)
	{
		if ( field[0][j].CellT == field[1][j].CellT == field[2][j].CellT )
		{
			if ( Cell::CellType::X == field[1][j].CellT )
				std::cout << "win_X" << std::endl;
				return WIN_X;
			if ( Cell::CellType::O == field[1][j].CellT )
				std::cout << "win_O" << std::endl;
				return WIN_O;
		}
	}

	if ( field[0][0].CellT == field[1][1].CellT == field[2][2].CellT ||
		field[0][2].CellT == field[1][1].CellT == field[2][0].CellT )
	{
		if ( Cell::CellType::X == field[1][1].CellT )
			return WIN_X;
		std::cout << "Win_x" << std::endl;
		if ( Cell::CellType::O == field[1][1].CellT )
			std::cout << "Win_o" << std::endl;
			return WIN_O;
	}

	for ( int i = 0; i < 3; i++ )
	{
		for ( int j = 0; j < 3; j++ ) 
		{
			if ( Cell::CellType::EMPTY == field[i][j].CellT )
				std::cout << "game" << std::endl;
				return GAME;
		}
	}
	std::cout << "draw" << std::endl;
	return DRAW;
}

void GameField::turn()
{
	static unsigned turns;
	++turns;// if odd - X's turn / even - O's
	unsigned row;
	unsigned column;
	std::cout << "Enter X coordinate:\n";
	std::cin >> row;
	std::cout << "Enter Y coordinate:\n";
	std::cin >> column;

	//if (field[row][column].CellT == Cell::EMPTY)
	{
		if ( turns % 2 != 0 ) field[row][column].CellT = Cell::X;
		if ( turns % 2 == 0 ) field[row][column].CellT = Cell::O;
	}	
	if ( turns == 10 ) turns = 0;
}

GameField::GameField(StateType givenType)
{
	StateT = givenType;
}

GameField::~GameField()
{
	delete[] field;
}
