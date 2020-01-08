#pragma once
#include "헤더.h"

#define SQUARE_BLOCK_COUNT 40
#define WALL_BLOCK_COUNT 158
#define HEART_BLOCK_COUNT 10

#define SHAPE_SUARE "▣" // defined은 무조건 대문자
#define SHAPE_WALL "▦"
#define SHAPE_HEART "♥"

#define RANDOM_X 96
#define RANDOM_Y 28

#define HEART_WALL_X_MIN 2
#define HEART_WALL_X_MAX 94
#define HEART_WALL_Y_MIN 1
#define HEART_WALL_Y_MAX 27

struct Blocks
{
	int m_ix;
	int m_iy;
	string m_ishape;
};

class Block
{
private:
	Blocks * Square;
	Blocks * Wall;
	Blocks * Heart;
	int m_icount;
public:
	void Map_Block();
	void Square_Block();
	void Heart_Block();
	bool Count_Square_Block(int x, int y);
	bool Count_Heart_Block(int x, int y);
	bool Count_Wall_Block(int x, int y);
	void Init_Heart_Block();
	void Map_Block_Create(int x, int y);
	void Map_Block_Draw();
	Block();
	~Block();

	static void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

