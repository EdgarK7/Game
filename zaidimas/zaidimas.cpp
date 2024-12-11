#include <raylib.h>
#include "../game.cpp"
#include "../colors.h"

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
	InitWindow (500, 620, "Tetris");
    SetTargetFPS (60);

	Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

	Game game = Game();
	
	while (WindowShouldClose() == false)
	{
		game.HandleInput();
		if (EventTriggered(0.5))
		{
			game.MoveBlockDown();
		}
		BeginDrawing();
		ClearBackground(darkblue);
		DrawTextEx(font, "Score", { 365,15 }, 38, 2,WHITE);
		DrawTextEx(font, "Next", { 370,175 }, 38, 2, WHITE);
		if (game.gameOver)
		{
			DrawTextEx(font, "GAME OVER", { 320,450 }, 30, 2, WHITE);
		}
		DrawRectangleRounded({ 320,55,170,60 }, 0.3, 6, lightblue);
		DrawRectangleRounded({ 320,215,170,180 }, 0.3, 6, lightblue);
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}
