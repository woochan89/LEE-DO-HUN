#pragma once
#include "Login.h"

class Computer : public Login
{
private:
	Register_id *create_com, *m_create_next_com, *m_tmp_com, *m_idcheck_com;
public:
	static int exit;
	void Go_Login();
	void Menu();
	void Menu2();
	void Util();
	void User_Info();
	void User_Info_Change();
	void Register();
	void User_Search();
	Computer();
	~Computer();
};

