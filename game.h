#pragma once
#include "grid.cpp"
#include "blocks.cpp"

using namespace std;

class Game 
{
public:
	Game();
	~Game();
	void Draw();
	void HandleInput();
	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();
	bool gameOver;
	int score;
	Music music;

private:
	Grid grid;
	bool IsBlockOutside();
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	void Reset();
	void UpdateScore(int linesClreared, int moveDownPoints);
	Block GetRandomBlock();
	vector<Block> GetAllBlocks();
	vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;
	Sound rotateSound;
	Sound clearSound;
};