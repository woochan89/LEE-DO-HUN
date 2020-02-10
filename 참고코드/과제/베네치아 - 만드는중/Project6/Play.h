#include "Mecro.h"
#include "Interface.h"
#include "WardManager.h"
#pragma once

#define FULL_HP 9
#define BACK_SPACE 8
#define ENTER 13

class Play : virtual public WardManager
{
private:
	int m_iLife;
	int m_iScore;
	int m_iStage;
	int m_iload_word;
	string m_iName;
	Interface Ui;
	_Ward *w;
public:
	Play();

	void Life_Name();
	void Start();
	void Game_Start();
	void Story();
	void Insert_Name();
	void Playing();
	~Play();
};

