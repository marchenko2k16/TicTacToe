#include "Engine.h"

void Engine::start()
{
	GameField *gField = new GameField();
	while (gField->GameState() == GameField::GAME)
	{
		Render::draw(gField);
		gField->turn();
	}
	std::cin.get();
}
