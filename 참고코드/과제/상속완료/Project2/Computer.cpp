#include "Computer.h"

int Computer::exit = FALSE;

Computer::Computer()
{
	create_com = NULL;
	m_create_next_com = NULL;
}


void Computer::User_Search()
{
	m_idcheck_com = create_com;

	for (int i = 0; i < m_icount; i++)
	{
		if (m_id_save == m_idcheck_com->id)
		{
			m_tmp_com = m_idcheck_com;
			break;
		}
		else
		{
			if (m_idcheck_com->m_pNext != NULL)
			{
				m_idcheck_com = m_idcheck_com->m_pNext;
			}
		}
	}
}

void Computer::User_Info()
{
	User_Search();
	system("cls");
	cout << "============회원 정보============" << endl;
	cout << "ID : " << m_tmp_com->id << "     닉네임 : " << m_tmp_com->nick_name << endl;
	cout << "나이 : " << m_tmp_com->age << "살" << "     휴대폰번호 : " << m_tmp_com->phone << endl;
	cout << "마일리지 : " << m_tmp_com->money << "원" << endl;
	system("pause");
}

void Computer::User_Info_Change()
{
	int select = 0;

	string change_nick = { 0 };
	string change_phone = { 0 };
	int change_age = 0;

	string ex_value = { 0 };
	int ex_value2 = 0;

	while (1)
	{
		User_Search();
		system("cls");
		cout << "============회원 정보============" << endl;
		cout << "ID : " << m_tmp_com->id << "     닉네임 : " << m_tmp_com->nick_name << endl;
		cout << "나이 : " << m_tmp_com->age << "살" << "     휴대폰번호 : " << m_tmp_com->phone << endl;
		cout << "마일리지 : " << m_tmp_com->money << "원" << endl;
		cout << "=================================" << endl;
		cout << "1.닉네임 변경" << endl;
		cout << "2.나이 변경" << endl;
		cout << "3.휴대폰 변경" << endl;
		cout << "4.돌아가기" << endl;
		cout << "입력 : ";
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "현재 닉네임 : " << m_tmp_com->nick_name << endl;
			ex_value = m_tmp_com->nick_name;
			cout << "변경할 닉네임 입력 : ";
			cin >> change_nick;
			m_tmp_com->nick_name = change_nick;
			cout << ex_value << " -> " << m_tmp_com->nick_name;
			break;
		case 2:
			cout << "현재 나이 : " << m_tmp_com->age << endl;
			ex_value2 = m_tmp_com->age;
			cout << "변경할 나이 입력 : ";
			cin >> change_age;
			m_tmp_com->age = change_age;
			cout << ex_value2 << " -> " << m_tmp_com->age;
			break;
		case 3:
			cout << "현재 번호 : " << m_tmp_com->phone << endl;
			ex_value = m_tmp_com->phone;
			cout << "변경할 번호 입력 : ";
			cin >> change_phone;
			m_tmp_com->phone = change_phone;
			cout << ex_value << " -> " << m_tmp_com->phone;
			break;
		case 4:
			return;
		}
	}

}

void Computer::Util()
{
	int select = 0;
	
	while (1)
	{
		system("cls");
		cout << "1.계 산 기" << endl;
		cout << "2.메 모 장" << endl;
		cout << "3.그 림 판" << endl;
		cout << "4.돌아 가기" << endl;
		cout << "선택 >>>> ";
		cin >> select;
		switch (select)
		{
		case 1:
			system("calc");
			break;
		case 2:
			system("notepad");
			break;
		case 3:
			system("mspaint");
			break;
		case 4:
			return;
		}
	}
}

void Computer::Register()
{
	int id_complete = FALSE;
	int pw_complete = FALSE;


	if (create_com == NULL)
	{
		create_com = new Register_id; // 첫 가입일때는 create를 쓴다.
		m_tmp_com = create_com;
	}
	else if (create_com != NULL)
	{
		m_create_next_com = new Register_id;
		m_tmp_com = m_create_next_com;
	}

	while (id_complete != TRUE)
	{
		id_complete = TRUE;
		system("cls");
		cout << "아이디 입력 (3글자 이상, 한글은 안됌) : ";
		cin >> m_tmp_com->id;
		if (m_icount != FALSE) // 아이디 한개 이상 만들어진 상태일때만 실행된다.
		{
			if (Id_Check(m_tmp_com->id, create_com, m_idcheck_com) == false)
			{
				cout << "중복된 아이디 입니다." << endl;
				_getch();
				id_complete = FALSE;
			}
		}
		if (m_tmp_com->id.length() < 3)
		{
			cout << "아이디가 세글자 이하입니다." << endl;
			_getch();
			id_complete = FALSE;
		}
		if (korean_check(m_tmp_com->id) == false)
		{
			cout << "아이디에 한글이 들어 갈 수 없습니다." << endl;
			_getch();
			id_complete = FALSE;
		}
	}

	while (pw_complete != TRUE)
	{
		pw_complete = TRUE;
		system("cls");
		cout << "비밀번호 입력 (8글자 이상, 영문과 숫자포함) : ";
		cin >> m_tmp_com->pw;
		cout << "비밀번호 확인 : ";
		cin >> m_tmp_com->pw_check;

		if (m_tmp_com->pw.length() < 8)
		{
			cout << "비밀번호가 여덟글자 이하 입니다." << endl;
			_getch();
			pw_complete = FALSE;
		}
		if (korean_check(m_tmp_com->pw) == false || korean_check(m_tmp_com->pw_check) == false)
		{
			cout << "비밀번호가 영문이 아닙니다." << endl;
			_getch();
			pw_complete = FALSE;
		}
		if (number_check(m_tmp_com->pw) == false)
		{
			cout << "숫자가 포함되어 있지 않습니다." << endl;
			_getch();
			pw_complete = FALSE;
		}
		if (pw_correct_check(m_tmp_com->pw, m_tmp_com->pw_check) == false)
		{
			cout << "비밀번호가 일치하지 않습니다." << endl;
			_getch();
			pw_complete = FALSE;
		}
	}
	system("cls");
	cout << "닉네임 입력 : ";
	cin >> m_tmp_com->nick_name;
	cout << "나이 입력 : ";
	cin >> m_tmp_com->age;
	cout << "휴대폰 번호 입력 : ";
	cin >> m_tmp_com->phone;
	m_tmp_com->money = 1000;
	m_icount++;
	m_tmp_com->m_pNext = NULL;

	cout << "회원가입 성공!! 마일리지 1000원 등록" << endl;


	if (m_create_next_com != NULL)
	{
		m_tmp_com = create_com;
		while (m_tmp_com->m_pNext != NULL)
		{
			m_tmp_com = m_tmp_com->m_pNext;
		}
		m_tmp_com->m_pNext = m_create_next_com;
	}

	system("pause");
}

void Computer::Go_Login()
{
	string tmp_id = { 0 };
	string tmp_pw = { 0 };
	int trigger = FALSE;

	while (trigger != TRUE)
	{
		trigger = TRUE;
		system("cls");
		cout << "아이디 입력 : ";
		cin >> tmp_id;
		cout << "비밀번호 입력 : ";
		cin >> tmp_pw;
		if (Id_Check(tmp_id, create_com, m_idcheck_com) == true)
		{
			cout << "아이디가 없습니다." << endl;
			trigger = FALSE;
			_getch();
		}
		if (pw_login_check(tmp_id, tmp_pw, create_com, m_idcheck_com) == false)
		{
			cout << "비밀번호가 틀렸습니다." << endl;
			trigger = FALSE;
			_getch();
		}
		m_login_check = TRUE; // 로그인 성공
	}
	m_id_save = tmp_id;
	m_pw_save = tmp_pw;
	cout << "이도헌 컴퓨터 ON" << endl;
	Sleep(4000);

}

void Computer::Menu()
{
	int num = 0;

	while (m_login_check != TRUE)
	{
		system("cls");
		cout << "=====Login=====<회원수[" << m_icount << "명]>" << endl;
		cout << "    1.회원 가입" << endl;
		cout << "    2.로그인" << endl;
		cout << "    3.종료" << endl;
		cout << "입력 : ";
		cin >> num;
		switch (num)
		{
		case 1:
			Register();
			break;
		case 2:
			if (create_com == NULL)
			{
				cout << "회원가입 부터 해주세요 !" << endl;
				system("pause");
			}
			else
			{
				Go_Login();
			}
			break;
		case 3:
			exit = TRUE;
			return;
		}
	}
}

void Computer::Menu2()
{
	int select = 0;

	while (1)
	{
		system("cls");
		cout << "===== 환 영 합 니 다 =====" << endl;
		cout << "1.컴퓨터 상태" << endl;
		cout << "2.기 능" << endl;
		cout << "3.회원 정보" << endl;
		cout << "4.회원 정보 변경" << endl;
		cout << "5.OFF" << endl;
		cout << "입력 >> ";
		cin >> select;
		switch (select)
		{
		case 1:
			Show_Computer();
			break;
		case 2:
			Util();
			break;
		case 3:
			User_Info();
			break;
		case 4:
			User_Info_Change();
			break;
		case 5:
			for (int i = 5; i > 0; i--)
			{
				cout << "종료 " << i << "초 전" << endl;
				Sleep(1000);
			}
			return;
		}
	}
}


Computer::~Computer()
{
	m_tmp_com = create_com;
	if (m_tmp_com == NULL)
	{
		return;
	}
	else
	{
		Release(m_tmp_com);
		delete m_tmp_com;
		m_tmp_com = NULL;
	}
}
