#include "Play.h"

Play::Play()
{
	m_iLife = FULL_HP;
	m_iScore = 0;
	m_iName = { 0 };
}

void Play::Start()
{
	int Select = 0;

	char buf[256];

	Ui.First_Screen();
	RED
	Ui.TextDraw("Life : ", 1, HEIGHT + 1);
	for (int i = 0, j = 8; i < m_iLife; i++) // 하트 보유수만큼 출력
	{
		Ui.HeartDraw(j, HEIGHT + 1);
		j += 2;
	}
	sprintf_s(buf, "Score : %d", m_iScore);
	Ui.DrawMidText(buf, WIDTH, HEIGHT + 1);
	Ui.DrawMidText("Name : 이름없음", WIDTH * 1.8, HEIGHT + 1);

	BLUE
	Ui.DrawMidText("1.Game Start", WIDTH , HEIGHT * 0.4);
	Ui.DrawMidText("2.Rank", WIDTH, HEIGHT * 0.4 + 3);
	Ui.DrawMidText("3.Exit", WIDTH, HEIGHT * 0.4 + 6);

	Select = Ui.MenuSelectCursor(3, 3, WIDTH * 0.4, HEIGHT * 0.4);

	if (Select == 1)
	{
		Game_Start();
	}

}

void Play::Game_Start()
{
	char buf[256];

	Ui.Game_Screen();

	RED
	Ui.TextDraw("Life : ", 1, HEIGHT + 1);
	for (int i = 0, j = 8; i < m_iLife; i++) // 하트 보유수만큼 출력
	{
		Ui.HeartDraw(j, HEIGHT + 1);
		j += 2;
	}
	sprintf_s(buf, "Score : %d", m_iScore);
	Ui.DrawMidText(buf, WIDTH, HEIGHT + 1);
	Ui.DrawMidText("Name : 이름없음", WIDTH * 1.8, HEIGHT + 1);
	BLUE
	Ui.DrawMidText("Skip : s", WIDTH, HEIGHT * 0.75);
	Story();
}

void Play::Story()
{
	int i = 0;
	int line = 0;
	string story_talk[26] = { "0" };
	ifstream Read;

	Read.open("베네치아_스토리.txt");




	if (!Read.eof())
	{
		Read >> line;
		while (line != 0)
		{
			getline(Read, story_talk[i]);
			i++;
			line--;
		}
	}




	for (int j = 0; j < i; j++)
	{
		Sleep(500);
		Ui.DrawMidText(story_talk[j], WIDTH, HEIGHT * 0.3 + j);
	}
}

Play::~Play()
{

}