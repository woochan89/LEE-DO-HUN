#include "Student.h"



Student::Student()
{
}

void Student::Input()
{
	cout << "학년 입력 : ";
	cin >> m_igrade;
	cout << "반 입력 : ";
	cin >> m_iclass;
	cout << "학생 번호 입력 : ";
	cin >> m_inum;

	cout << "나이 입력 : ";
	cin >> m_iage;
	cout << "이름 입력 : ";
	cin >> m_iname;
	cout << "성별 입력 : ";
	cin >> m_isex;
}

void Student::Show()
{
	system("cls");
	cout << m_igrade << "학년 " << m_iclass << "반 " << m_inum << "번 학생" << endl;
	cout << "나이 : " << m_iage << "세" << endl;
	cout << "이름 : " << m_iname << endl;
	cout << "성별 : " << m_isex << endl;
}

Student::~Student()
{
}
