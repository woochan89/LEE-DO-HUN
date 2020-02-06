#include "Mecro.h"
#include "Interface.h"
#pragma once

#define FULL_HP 9

class Play
{
private:
	int m_iLife;
	int m_iScore;
	string m_iName;
	Interface Ui;
public:
	Play();

	void Start();
	void Game_Start();
	void Story();
	~Play();
};

