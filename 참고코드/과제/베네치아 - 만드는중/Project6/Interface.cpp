#include "Interface.h"


Interface::Interface()
{

}

void Interface::Life_Show(int num)
{
	// 맵드로우 하트그리는것 추가
	// 화면 회색은 보류
}

void Interface::First_Screen()
{
	system("cls");
	PLUM
	BoxDraw(0, 0, WIDTH, HEIGHT);
	BLUE
	DrawMidText("☆ ★ 베 네 치 아 ☆ ★", WIDTH, HEIGHT * 0.2);
	_getch();
}

Interface::~Interface()
{

}