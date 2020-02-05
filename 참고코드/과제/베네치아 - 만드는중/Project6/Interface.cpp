#include "Interface.h"


Interface::Interface()
{

}

void Interface::First_Screen()
{
	system("cls");
	PLUM
	BoxDraw(0, 0, WIDTH, HEIGHT);
	BLUE
	DrawMidText("☆ ★ 베 네 치 아 ☆ ★", WIDTH, HEIGHT * 0.2);
	LittleBox(WIDTH, HEIGHT * 0.7, WIDTH * 0.3, HEIGHT * 0.15);
}

Interface::~Interface()
{

}