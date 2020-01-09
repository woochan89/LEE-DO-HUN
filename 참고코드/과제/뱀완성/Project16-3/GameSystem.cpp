#include "GameSystem.h"


GameSystem::GameSystem()
{
	m_iwidth = 50;
	m_iheight = 30;
	m_iscore = 0;
	m_igame_state = TRUE;
}

void GameSystem::Game_Start()
{
	int old_time, cur_time = 0;
	system("cls");
	Block::gotoxy(m_iwidth, m_iheight + 2);
	cout << "Score : " << m_iscore;

	Draw_Block.Init_Heart_Block();
	Draw_Block.Map_Block_Draw();
	Draw_Snake.Create_Head();
	Draw_Block.Square_Block();

	old_time = clock();

	while (m_igame_state)
	{
		cur_time = clock();
		if (cur_time - old_time >= 1000)
		{
			Draw_Block.Heart_Block();
			old_time = cur_time;
		}
		Snake_Control();
	}
}

void GameSystem::Snake_Control()
{
	Draw_Snake.Snake_Move();

	if (Crash_Square() == true)
	{
		m_igame_state = FALSE;
	}
	if (Crash_Wall() == true)
	{
		m_igame_state = FALSE;
	}
	if (Draw_Snake.Snake_Crash() == true)
	{
		m_igame_state = FALSE;
	}
	if (Eat_Heart() == true)
	{
		Draw_Snake.Create_Tail();
		m_iscore++;
		Block::gotoxy(m_iwidth, m_iheight + 2);
		cout << "Score : " << m_iscore;
	}
}

bool GameSystem::Crash_Square()
{
	if (Draw_Block.Count_Square_Block(Draw_Snake.Get_m_MyPositiion_x(), Draw_Snake.Get_m_MyPositiion_y()) == true)
	{
		return true;
	}
	return false;
}

bool GameSystem::Crash_Wall()
{
	if (Draw_Block.Count_Wall_Block(Draw_Snake.Get_m_MyPositiion_x(), Draw_Snake.Get_m_MyPositiion_y()) == true)
	{
		return true;
	}
	return false;
}

bool GameSystem::Eat_Heart()
{
	if (Draw_Block.Count_Heart_Block(Draw_Snake.Get_m_MyPositiion_x(), Draw_Snake.Get_m_MyPositiion_y()) == true)
	{
		return true;
	}
	return false;
}

void GameSystem::Game_Over()
{
	int trigger = FALSE;

	system("cls");
	Draw_Block.Map_Block_Draw();
	Block::gotoxy(m_iwidth, m_iheight + 2);
	cout << "Score : " << m_iscore;
	Block::gotoxy(m_iwidth * 0.75, m_iheight * 0.45);
	cout << "☆ ● ☆ 게임 오버 ☆ ● ☆";
	Block::gotoxy(m_iwidth * 0.68, m_iheight * 0.55);
	cout << "계속하려면 스페이스바를 눌러주세요";
	
	while (trigger == FALSE)
	{
		char ch = _getch();
		if (ch == SPACE_BAR)
		{
			trigger = TRUE;
			m_igame_state = TRUE;
		}
	}

}

void GameSystem::Menu()
{
	int select = 0;

	while (1)
	{
		system("cls");
		Draw_Block.Map_Block_Draw();
		Block::gotoxy(m_iwidth * 0.75, m_iheight * 0.25);
		cout << "☆ ● ☆ 뱀 게임 ☆ ● ☆";
		Block::gotoxy(m_iwidth * 0.88, m_iheight * 0.35);
		cout << "1.게임 시작";
		Block::gotoxy(m_iwidth * 0.88, m_iheight * 0.45);
		cout << "2.게임 종료";
		Block::gotoxy(m_iwidth * 0.94, m_iheight * 0.55);
		cout << "선택 : ";
		Block::gotoxy(m_iwidth, m_iheight + 2);
		cout << "Score : " << m_iscore;
		Block::gotoxy(m_iwidth * 1.1, m_iheight * 0.55);
		cin >> select;
		switch (select)
		{
		case 1:
			Game_Start();
			break;
		case 2:
			return;
		}

		if (m_igame_state == FALSE)
		{
			m_iscore = 0;  // 점수, 스피드, 방향 초기화
			Snake::m_iSpeed = 300;
			Snake::direct = NULL;
			Game_Over();
		}
	}

}

void GameSystem::Init()
{
	Draw_Block.Map_Block();
	Menu();
}

GameSystem::~GameSystem()
{
}
