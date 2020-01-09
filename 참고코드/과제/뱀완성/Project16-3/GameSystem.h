#pragma once
#include "Snake.h"

#define SPACE_BAR 32

class GameSystem
{
private:
	int m_iwidth;
	int m_iheight;
	int m_iscore;
	int m_igame_state;
	Block Draw_Block;
	Snake Draw_Snake;
public:
	void Init();
	void Menu();
	void Game_Start();
	void Snake_Control();
	bool Crash_Square();
	bool Eat_Heart();
	bool Crash_Wall();
	void Game_Over();
	GameSystem();
	~GameSystem();

};

