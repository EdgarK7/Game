#include <raylib.h>
#include "../grid.cpp"
#include "../blocks.cpp"

int main()
{
	Color background = { 44,44,127,255 };
	InitWindow (300, 600, "Tetris");
    SetTargetFPS (60);

	Grid grid = Grid();
	grid.Print();

	Tblock block = Tblock();
	
	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(background);
		grid.Draw();
		block.Draw();
		EndDrawing();
	}

	CloseWindow();
}
