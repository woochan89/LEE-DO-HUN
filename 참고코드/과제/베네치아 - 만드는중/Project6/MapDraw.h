#pragma once
#include"Mecro.h"

#define UP 'w'
#define DOWN 's'
#define ENTER 13


class MapDraw
{
public:
	void BoxDraw(int Start_x, int Start_y, int Width, int Height);
	void BoxErase(int Width, int Height);
	void DrawPoint(string str, int x, int y);
	void DrawMidText(string str, int x, int y);
	void TextDraw(string str, int x, int y);
	void ErasePoint(int x, int y);
	void HeartDraw(int x, int y);// 하트 그리기
	void EraseHeart(int x, int y);// 하트 삭제
	void LittleBox(int Start_x, int Start_y, int Width, int Height);// 작은박스
	int MenuSelectCursor(int MenuLen, int AddCol, int x, int y);
	MapDraw();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~MapDraw();
};