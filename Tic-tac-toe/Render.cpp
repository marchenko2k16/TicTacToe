#include "Render.h"

void Render::ClearScreen()
  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if ( hStdOut == INVALID_HANDLE_VALUE ) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }

void Render::draw(GameField* gf)
{
	//Render::ClearScreen();
	Cell **gameField = gf->getField();

	for ( int i = 0; i < 3; i++ )
	{
		std::cout << "-------------\n" << "|";
		for ( int j = 0; j < 3; j++ )
		{

			switch ( gameField[i][j].CellT )
			{
			case Cell::EMPTY :
				std::cout << "   ";
				break;
			case Cell::X :
				std::cout << " X ";
				break;
			case Cell::O :
				std::cout << " O ";
				break;
			};
			std::cout << "|";
		}		
		std::cout << "\n";
		std::cout << "-------------\n";
	}
}