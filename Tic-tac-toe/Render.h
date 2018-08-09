#pragma once
#include <Windows.h>
#include "GameField.h"
#include <iostream>

class Render
{
private:
	static void ClearScreen();
public:
	static void draw( GameField* );
};
