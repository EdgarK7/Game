#include <raylib.h>
#include "../game.cpp"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

int main()
{
	Color background = { 44,44,127,255 };
	InitWindow (300, 600, "Tetris");
    SetTargetFPS (60);

	Game game = Game();
	
	while (WindowShouldClose() == false)
	{
		game.HandleInput();
		if (EventTriggered(0.5))
		{
			game.MoveBlockDown();
		}
		BeginDrawing();
		ClearBackground(background);
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}
