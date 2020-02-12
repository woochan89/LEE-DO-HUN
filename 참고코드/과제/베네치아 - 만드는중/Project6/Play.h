#include "Mecro.h"
#include "Interface.h"
#include "WardManager.h"
#pragma once

#define FULL_HP 9
#define BACK_SPACE 8
#define ENTER 13
#define INSERT_WORD_MAX 19

class Play : virtual public WardManager
{
private:
	int m_iLife;
	int m_iScore;
	int m_iStage;
	int m_iload_word;
	int m_inum;
	int m_ipause;
	char m_iTmp_Iw[INSERT_WORD_MAX];
	string m_iName;
	string m_iWord;
	string m_iTmpWord;
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
	void Draw_Drop();
	void Insert_Word();
	void Correct_Word();
	~Play();
};

