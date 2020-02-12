#include "Play.h"

Play::Play()
{
	m_iLife = FULL_HP;
	m_iScore = 0;
	m_iName = { "\0" };
	m_iWord = { "\0" };
	m_iTmpWord = { "\0" };
	m_iStage = 1;
	m_iload_word = 0; // �� �ܾ� ����
	w = NULL; // �ܾ�
	m_inum = 0;
	m_iTmp_Iw[INSERT_WORD_MAX] = { '\0' };
	m_ipause = FALSE; // �߸��Է½� �г�Ƽ �ο� ����
}

void Play::Life_Name()
{
	char buf[256];

	RED
	Ui.TextDraw("Life : ", 1, HEIGHT + 1);
	for (int i = 0, j = 8; i < m_iLife; i++) // ��Ʈ ��������ŭ ���
	{
		Ui.HeartDraw(j, HEIGHT + 1);
		j += 2;
	}
	sprintf_s(buf, "Score : %d", m_iScore);
	Ui.DrawMidText(buf, WIDTH, HEIGHT + 1);
	if (m_iName == "\0")
	{
		Ui.DrawMidText("Name : �̸�����", WIDTH * 1.8, HEIGHT + 1);
	}
	else
	{
		Ui.DrawMidText("Name : " + m_iName, WIDTH * 1.8, HEIGHT + 1);
	}
}

void Play::Start()
{
	int Select = 0;

	if (w != NULL)
	{
		delete[] w;
	}
	w = new _Ward[WARD_MAX]; // �̸� ������ �Ҵ��ؾ� Load_Ward ���� �����̉�

	Load_Ward(w, m_iload_word);	// �ܾ� �ҷ�����
	Set_xy(w); // �ܾ� ��ġ ����

	Ui.First_Screen();
	Life_Name();

	BLUE
	Ui.DrawMidText("1.Game Start", WIDTH , HEIGHT * 0.4);
	Ui.DrawMidText("2.Rank", WIDTH, HEIGHT * 0.4 + 3);
	Ui.DrawMidText("3.Exit", WIDTH, HEIGHT * 0.4 + 6);

	Select = Ui.MenuSelectCursor(3, 3, WIDTH * 0.4, HEIGHT * 0.4);

	if (Select == 1)
	{
		Game_Start();
	}

}

void Play::Game_Start()
{

	Ui.Game_Screen();
	Life_Name();

	BLUE
	Ui.DrawMidText("Skip : s", WIDTH, HEIGHT * 0.75);

	Story();
	Insert_Name();
	Playing();
}

void Play::Story()
{
	int i = 0;
	int line = 0;
	string story_talk[26] = { "0" };
	char ch = 0;
	ifstream Read;

	Read.open("����ġ��_���丮.txt");




	if (!Read.eof())
	{
		Read >> line;
		while (line != 0)
		{
			getline(Read, story_talk[i]);
			i++;
			line--;
		}
	}


	for (int j = 0, k = 0, n = 0; j < i; j++)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 's')
			return;
		}

		Sleep(500);
		if (j > 9)
		{
			k = 0;
			n += 1;
			while (k != j - n)
			{
				if (_kbhit())
				{
					ch = _getch();
					if (ch == 's')
						return;
				}

				Ui.DrawMidText("                                          ", WIDTH, HEIGHT * 0.2 + k);
				Ui.DrawMidText(story_talk[k + n], WIDTH, HEIGHT * 0.2 + k);
				k++;
			}
			Ui.DrawMidText("                                          ", WIDTH, HEIGHT * 0.2 + j - n);
			Ui.DrawMidText(story_talk[j], WIDTH, HEIGHT * 0.2 + j - n);
		}
		else
		Ui.DrawMidText(story_talk[j], WIDTH, HEIGHT * 0.2 + j);
	}
}

void Play::Insert_Name()
{
	char ch = 0;
	char name_tmp[9] = { '\0' };
	int num = 0;
	string tmp = { "\0" };

	Ui.Game_Screen();
	Life_Name();


	BLUE
	Ui.DrawMidText("�̸� �Է�", WIDTH, HEIGHT * 0.75 - 5);
	Ui.gotoxy(WIDTH, HEIGHT * 0.75);

	while (1)
	{
		ch = _getch();

		if (ch == BACK_SPACE && num >= 1)
		{
			num--;
			name_tmp[num] = { '\0' };
			tmp = { "\0" };
			for (int i = 0; i < num; i++)
			{
				tmp += name_tmp[i];
			}
			Ui.DrawMidText("                   ", WIDTH, HEIGHT * 0.75 - 4);
		}

		else if (name_tmp[8] != NULL)
		{
			Ui.DrawMidText("10���� �ʰ�!!", WIDTH, HEIGHT * 0.75 - 4);
			_getch();
		}

		else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
			name_tmp[num] = ch;
			tmp += name_tmp[num];
			num++;
		}

		else if (ch == ENTER)
		{
			m_iName = tmp;
			break;
		}

		Ui.DrawMidText("                    ", WIDTH, HEIGHT * 0.75);
		Ui.DrawMidText(tmp, WIDTH, HEIGHT * 0.75);
	}

	// �����̿ܿ��� �Է¾ȵǰ� �ѱ��� �ٷ�������
	// 9���� ����, �Է��ϴ� ��� �ؽ�Ʈ�� �߾ӿ� ������
}

void Play::Insert_Word()
{
	char ch = 0;

	BLUE
	Ui.gotoxy(WIDTH, HEIGHT * 0.75);

	ch = _getch();

	if (ch == BACK_SPACE && m_inum >= 1)
	{
		m_inum--;
		m_iTmp_Iw[m_inum] = { '\0' };
		m_iTmpWord = { "\0" };
		for (int i = 0; i < m_inum; i++)
		{
			m_iTmpWord += m_iTmp_Iw[i];
		}
		Ui.DrawMidText("                   ", WIDTH, HEIGHT * 0.75 - 4);
	}

	else if (m_iTmp_Iw[18] != NULL)
	{
		Ui.DrawMidText("20���� �ʰ�!!", WIDTH, HEIGHT * 0.75 - 4);
		_getch();
	}

	else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
	{
		m_iTmp_Iw[m_inum] = ch;
		m_iTmpWord += m_iTmp_Iw[m_inum];
		m_inum++;
	}

	else if (ch == ENTER)
	{
		m_iWord = m_iTmpWord;
		m_iTmpWord = { "\0" }; // �����ܾ ���� �ʱ�ȭ
		m_inum = 0;
		m_iTmp_Iw[INSERT_WORD_MAX] = { '\0' };
		Correct_Word();
		Life_Name(); // ����ÿ� ���� �ٷ� ���
	}

	Ui.DrawMidText("                    ", WIDTH, HEIGHT * 0.75);
	Ui.DrawMidText(m_iTmpWord, WIDTH, HEIGHT * 0.75);
}

void Play::Draw_Drop()
{
	int printed_word[WARD_MAX] = {'\0'};
	int word_num = 0;
	int num = 0;

	int old_time = 0;
	int cur_time = 0;
	int move_time = 0;

	int pause_old_time = 0;
	int pause_cur_time = 0;

	move_time = clock();
	old_time = clock();
	pause_old_time = clock();

	while (word_num != WARD_MAX)
	{
		cur_time = clock();
		pause_cur_time = clock();

		if (_kbhit() && m_ipause == FALSE)
		{
			Insert_Word();
		}

		if (clock() - move_time >= 500 && word_num != NULL)
		{
			for (int i = 0; i < num; i++) // ��µȰ��� ���� �����̰� �ϱ�
			{
				Drop_Word(w, printed_word[i]);
			}
			move_time = clock();
			BLUE
			Ui.LittleBox(WIDTH, HEIGHT * 0.7, WIDTH * 0.3, HEIGHT * 0.15);
			if (m_iTmpWord.length() != 0) // �Է�â �����̴°� ����
			Ui.DrawMidText(m_iTmpWord, WIDTH, HEIGHT * 0.75);
		}
		if (cur_time - old_time >= 2000)
		{
			printed_word[num] = Draw_Word(w, printed_word[num]); // �ܾ� ���
			word_num++; // �ܾ� ����
			num++;
			old_time = cur_time;
		}

		if (m_ipause == TRUE) // �г�Ƽ �ɷ����� if��
		{
			if (pause_cur_time - pause_old_time >= 7000)
			{
				m_ipause = FALSE;
				pause_old_time = pause_cur_time;
				// ���߰� �����Է� �����̵Ǵ°� ��ġ��
			}
		}
	}
}

void Play::Correct_Word() // �ܾ� ���߸� ������ ������
{
	int num = 0;

	for (int i = 0; i < WARD_MAX; i++)
	{
		if (m_iWord == w[i].name)
		{
			if (w[i].status == TRUE)
			{
				num = w[i].name.length(); // �ܾ� ���� ����

				Ui.gotoxy(w[i].x, w[i].y);
				Ui.EraseWord(num);
				w[i].status = FALSE;
				m_iScore += 153 * (m_iStage * 0.5);
				return;
			}
		}	
	}
	m_ipause = TRUE; // Ʋ���� TRUE��
}

void Play::Playing()
{
	char buf[256];
	sprintf_s(buf, "�� %d Stage ��", m_iStage);

	PLUM
	Ui.BoxDraw(0, 0, WIDTH, HEIGHT);
	BLUE
	Ui.DrawMidText(buf, WIDTH, HEIGHT * 0.4);
	Life_Name();

	Sleep(2000);
	system("cls");
	Ui.Game_Screen();
	Life_Name();
	Draw_Drop(); //�ܾ� �׸��� ���������Լ�
}

Play::~Play()
{
	if (w != NULL)
	{
		delete[] w;
	}
	w = NULL;
}