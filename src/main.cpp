#include "game/Game.h"
#include "tools/Time.h"

int main()
{
	Game& game = Game::GetInstance();

	try
	{
		while (game.IsRunning())
		{
			game.HandleInput();
			game.Update(Time::DeltaTime());
			game.Render();
		}
	}
	catch (const GameException& error)
	{
		game.HandleGameException(error);
	}
	catch (const std::exception& error)
	{
		game.HandleOtherException(error);
	}

	return 0;
}