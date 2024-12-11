#include <raylib.h>
#include "../game.cpp"

int main()
{
	Color background = { 44,44,127,255 };
	InitWindow (300, 600, "Tetris");
    SetTargetFPS (60);

	Game game = Game();
	
	while (WindowShouldClose() == false)
	{
		game.HandleInput();
		BeginDrawing();
		ClearBackground(background);
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}
