#include "WardManager.h"

WardManager::WardManager()
{

}

void WardManager::Load_Ward(_Ward *name, int ward_max)
{
	ifstream Load;
	int j = 0;

	for (int i = 0; i < WARD_MAX; i++)
	{
		name[i].x = NULL;
		name[i].y = NULL;
		name[i].name = { "\0" };
		name[i].status = TRUE;
	}

	Load.open("Word.txt");
	if (!Load)
	{
		system("cls");
		cout << "해당 파일이 없습니다" << endl;
		_getch();
	}
	else
	{
		Load >> ward_max;
		while(!Load.eof())
		{
			Load >> name[j].name;
			j++; // 0 ~ 74까지 저장되고 마지막에 75가 됌
		}
	}

}

void WardManager::Set_xy(_Ward *name)
{
	int check = FALSE;

	for (int i = 0; i < WARD_MAX;)
	{
		name[i].x = (rand() % 64);
		name[i].y = 2;

		if (name[i].x >= 2 && name[i].x <= 63) // 0,1 제외 65, 64 제외
		{
			i++;
		}
	}

}

void WardManager::Draw_Word(_Ward *name)
{
	// 살아있는상태인 단어를 랜덤으로 출력

	int i = 0;
	int old_time = 0;
	int cur_time = 0;

	old_time = clock();

	while (1)
	{
		cur_time = clock();

		if (cur_time - old_time >= 2000)
		{
			i = (rand() % 75);

			if (name[i].status == TRUE)
			{
				XY.gotoxy(name[i].x, name[i].y);
				cout << name[i].name;

				old_time = cur_time;
			}
		}

	}
	// 위의 코드는 play로 옮기고, 하나씩 단어 관리하기
}

WardManager::~WardManager()
{

}