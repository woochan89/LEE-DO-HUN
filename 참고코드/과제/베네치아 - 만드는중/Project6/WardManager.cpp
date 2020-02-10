#include "WardManager.h"

WardManager::WardManager()
{

}

void WardManager::Load_Ward(_Ward *name, int ward_max)
{
	ifstream Load;
	int j = 0;

	if (name != NULL)
	{
		delete[] name;
	}
	name = new _Ward[WARD_MAX];

	for (int i = 0; i < WARD_MAX; i++)
	{
		name[i].x = NULL;
		name[i].y = NULL;
		name[i].name = { "\0" };
		name[i].status = 1;
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
	for (int i = 0; i < WARD_MAX; i++)
	{
		name[i].x = ((rand() >= 2) && (rand() <= 63)); // 0,1 제외 65, 64 제외
		name[i].y = 2;
	}
}

WardManager::~WardManager()
{

}