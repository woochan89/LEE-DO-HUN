#include "Mecro.h"
#include "Interface.h"
#pragma once

#define FULL_HP 9
#define BACK_SPACE 8
#define ENTER 13

class Play
{
private:
	int m_iLife;
	int m_iScore;
	int m_iStage;
	string m_iName;
	Interface Ui;
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

