#pragma once
#include<iostream>
#include<string>
#include<time.h>
#include<Windows.h>
#include<conio.h>
using namespace std;

struct Register_id
{
	string id;
	string pw;
	string pw_check;
	string nick_name;
	int age;
	string phone;
	int money;
	Register_id *m_pNext;
};

class Login
{
private:
public:
	static int m_login_check;
	static string m_id_save;
	static string m_pw_save;
	static int m_icount;
	bool Id_Check(string str, Register_id *Node1, Register_id *Node4);
	bool korean_check(string str);
	bool number_check(string str);
	bool pw_correct_check(string str1, string str2);
	void Release(Register_id *Node);
	bool pw_login_check(string str1, string str2, Register_id *Node1, Register_id *Node4);
	void Show_Computer();
	void Change_Login_Status(int num);
	Login();
	~Login();
};

