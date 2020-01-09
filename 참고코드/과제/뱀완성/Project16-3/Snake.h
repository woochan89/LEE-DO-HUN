#pragma once
#include "Block.h"

#define SNAKE_HEAD "¢Á"
#define SNAKE_TAIL "¡Û"

#define SNAKE_START_X 50
#define SNAKE_START_Y 15

enum GAME_KEY
{
	UP = 'w',
	DOWN = 's',
	RIGHT = 'd',
	LEFT = 'a',
};

struct Position
{
	int m_ix;
	int m_iy;
};

struct Snakes
{
	Position m_MyPositiion;
	Position m_LastPositiion;
	Snakes *m_pNext; // ²¿¸®
};

class Snake
{
private:
	Snakes *m_pHead, *m_pTail, *m_pTmp, *m_pMovetmp, *m_pMovetmp2;
	Snakes *m_pCrashtmp, *m_pCrashtmp2;
public:
	static int direct;
	static int key;
	static int m_iSpeed;
	void Snake_Move();
	void Snake_Move_Tmp();
	void Snake_Show();
	void Snake_Direct(int dir);
	void Create_Head();
	void Create_Tail();
	void Snake_Tail_Move();
	bool Snake_Crash();
	void Release(Snakes* Node);

	inline int Get_m_MyPositiion_x()
	{
		return m_pHead->m_MyPositiion.m_ix;
	}

	inline int Get_m_MyPositiion_y()
	{
		return m_pHead->m_MyPositiion.m_iy;
	}
	Snake();
	~Snake();
};

