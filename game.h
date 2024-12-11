#pragma once
#include "grid.cpp"
#include "blocks.cpp"

using namespace std;

class Game 
{
public:
	Game();
	Block GetRandomBlock();
	vector<Block> GetAllBlocks();
	void Draw();
	void HandleInput();
	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();
	Grid grid;
private:
	bool IsBlockOutside();
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;
};