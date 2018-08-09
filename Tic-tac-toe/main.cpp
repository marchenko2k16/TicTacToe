#pragma once
#include "Engine.h"

int main()
{	
	Engine *e = new Engine();
	(*e).start();
	
	std::cin.get();
	return(0);
}

