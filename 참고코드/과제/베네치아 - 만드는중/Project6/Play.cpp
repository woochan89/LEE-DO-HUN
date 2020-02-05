#include "Play.h"

Play::Play()
{
	m_iLife = FULL_HP;
	m_iScore = 0;
	m_iName = { 0 };
}

void Play::Start()
{
	char buf[256];

	Ui.First_Screen();
	RED
	Ui.TextDraw("Life : ", 1, HEIGHT + 1);
	for (int i = 0, j = 8; i < m_iLife; i++) // 하트 보유수만큼 출력
	{
		Ui.HeartDraw(j, HEIGHT + 1);
		j += 2;
	}
	sprint(buf, "Score : %d", m_iScore);
	Ui.DrawMidText(buf,)

}

Play::~Play()
{

}