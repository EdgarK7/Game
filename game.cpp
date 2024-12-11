#include "game.h"
#include <random>

using namespace std;

Game::Game()
{
	grid = Grid();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock()
{
	if (blocks.empty())
	{
		blocks = GetAllBlocks();
    }
	int randomIndex = rand() % blocks.size();
	Block block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);
	return block;
}

vector<Block> Game::GetAllBlocks()
{
	return {Iblock(),Jblock(), Lblock(), Oblock(), Sblock(), Tblock(),Zblock()};
}

void Game::Draw()
{
	grid.Draw();
	currentBlock.Draw();
}

void Game::HandleInput()
{
	int keyPressed = GetKeyPressed();
	switch (keyPressed)
	{
	case KEY_LEFT:
		MoveBlockLeft();
		break;
	case KEY_RIGHT:
		MoveBlockRight();
		break;
	case KEY_DOWN:
		MoveBlockDown();
		break;
	case KEY_UP:
		RotateBlock();
		break;
	}
}

void Game::MoveBlockLeft()
{
	currentBlock.Move(0, -1);
	if (IsBlockOutside() || BlockFits() == false)
	{
		currentBlock.Move(0, 1);
	}
}

void Game::MoveBlockRight()
{
	currentBlock.Move(0, 1);
	if (IsBlockOutside() || BlockFits() == false)
	{
		currentBlock.Move(0, -1);
	}
}

void Game::MoveBlockDown()
{
	currentBlock.Move(1, 0);
	if (IsBlockOutside() || BlockFits() == false)
	{
		currentBlock.Move(-1, 0);
		LockBlock();
	}
}

bool Game::IsBlockOutside()
{
	vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		if (grid.IsCellOutside(item.row, item.col))
		{
			return true;
		}
	}
	return false;
}

void Game::RotateBlock()
{
	currentBlock.Rotate();
	if (IsBlockOutside() || BlockFits() == false)
	{
		currentBlock.UndoRotation();
	}
}

void Game::LockBlock()
{
	vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		grid.grid[item.row][item.col] = currentBlock.id;
	}
	currentBlock = nextBlock;
	nextBlock = GetRandomBlock();
}

bool Game::BlockFits()
{
	vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		if (grid.IsCellEmpty(item.row, item.col) == false)
		{
			return false;
		}
	}
	return true;
}
