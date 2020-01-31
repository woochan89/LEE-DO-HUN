#include "Shop.h"



Shop::Shop()
{
	tmp_page1 = NULL;
	tmp_page2 = NULL;
	tmp_page3 = NULL;
	Dagger = NULL;
	Gun = NULL;
	Sword = NULL;
	Wand = NULL;
	Bow = NULL;
	Hammer = NULL;
}

int Shop::Create_Weapon(string name)
{
	int j = 0;

	for (int i = 0; i < MAX_WEAPON; i++)
	{
		if (wp[i].weapon_type == name)
		{
			j++;
		}
	}
	return j;
}

void Shop::Create_Weapon2(string name, Weapon_Info *wp_name)
{
	int j = 0;

	for (int i = 0; i < MAX_WEAPON; i++)
	{
		if (wp[i].weapon_type == name)
		{
			wp_name[j].weapon_type = wp[i].weapon_type;
			wp_name[j].weapon_name = wp[i].weapon_name;
			wp_name[j].weapon_dmg = wp[i].weapon_dmg;
			wp_name[j].weapon_price = wp[i].weapon_price;
			j++;
		}
	}
	wp_name->weapon_max_count = j;
}

void Shop::Init_Weapon()
{
	int i = 0;
	int num = 0;

	Init(wp);
	wp = new Weapon_Info[MAX_WEAPON];

	ifstream load;
	load.open("WeaponList.txt");

	while (!load.eof())
	{
		load >> wp[i].weapon_type;
		load >> wp[i].weapon_name;
		load >> wp[i].weapon_dmg;
		load >> wp[i].weapon_price;

		i++; // 다음무기
	}

	load.close();

	if (tmp_page1 != NULL)
	{
		delete[] tmp_page1;
	}
	tmp_page1 = new Weapon_Info[MAX_WEAPON];
	if (tmp_page2 != NULL)
	{
		delete[] tmp_page2;
	}
	tmp_page2 = new Weapon_Info[MAX_WEAPON];
	if (tmp_page3 != NULL)
	{
		delete[] tmp_page3;
	}
	tmp_page3 = new Weapon_Info[MAX_WEAPON];

	////////////////
	if (Dagger != NULL)
	{
		delete[] Dagger;
	}
	if (Gun != NULL)
	{
		delete[] Gun;
	}
	if (Sword != NULL)
	{
		delete[] Sword;
	}
	if (Wand != NULL)
	{
		delete[] Wand;
	}
	if (Bow != NULL)
	{
		delete[] Bow;
	}
	if (Hammer != NULL)
	{
		delete[] Hammer;
	}
	/////////////////////

	num = Create_Weapon("Dagger");
	Dagger = new Weapon_Info[num];
	Create_Weapon2("Dagger", Dagger);

	num = Create_Weapon("Gun");
	Gun = new Weapon_Info[num];
	Create_Weapon2("Gun", Gun);

	num = Create_Weapon("Sword");
	Sword = new Weapon_Info[num];
	Create_Weapon2("Sword", Sword);

	num = Create_Weapon("Wand");
	Wand = new Weapon_Info[num];
	Create_Weapon2("Wand", Wand);

	num = Create_Weapon("Bow");
	Bow = new Weapon_Info[num];
	Create_Weapon2("Bow", Bow);

	num = Create_Weapon("Hammer");
	Hammer = new Weapon_Info[num];
	Create_Weapon2("Hammer", Hammer);
}

void Shop::Weapon_Show(Weapon_Info *wp_name, int ht1, int ht2, int num)
{
	int n = 0;


	YELLOW
	while (n != num) // 해당무기의 끝부분까지
	{
		Draw_Gotoxy.gotoxy(WIDTH * 0.55, HEIGHT * 0.07 + ht1);
		cout << "가격 : " << wp_name[n].weapon_price << " 무기타입 : " << wp_name[n].weapon_type;
		Draw_Gotoxy.gotoxy(WIDTH * 0.44, HEIGHT * 0.07 + ht2);
		cout << "무기이름 : " << wp_name[n].weapon_name << " 공격력 : " << wp_name[n].weapon_dmg;
		ht1 += 3;
		ht2 += 3;
		n++; // 다음 무기
	}

	ORIGINAL
	Draw_Gotoxy.gotoxy(WIDTH * 0.84, HEIGHT * 0.07 + ht1);
	cout << "이전페이지";
	Draw_Gotoxy.gotoxy(WIDTH * 0.84, HEIGHT * 0.07 + ht2 + 2);
	cout << "다음페이지";
	Draw_Gotoxy.gotoxy(WIDTH * 0.9, HEIGHT * 0.07 + ht2 + 5);
	cout << "나가기";
}

int Shop::Buy_Weapon(Weapon_Info *wp_name, Character_Info *cr_name, int select_menu, int page)
{
	if (select_menu <= page)
	{
		if (cr_name->gold >= wp_name[select_menu - 1].weapon_price)
		{
			cr_name->cr_weapon_type = wp_name[select_menu - 1].weapon_type;
			cr_name->cr_weapon_name = wp_name[select_menu - 1].weapon_name;
			cr_name->cr_weapon_dmg = wp_name[select_menu - 1].weapon_dmg;
			cr_name->gold -= wp_name[select_menu - 1].weapon_price;
		}

	}
	else if (select_menu == page + 1)
	{
		return 0;
	}
	else if (select_menu == page + 2)
	{
		return 1;
	}
	else if (select_menu == page + 3)
	{
		return 2;
	}
}

void Shop::Weapon_Shop(Weapon_Info *wp_name, Character_Info *cr_name)
{
	int select = 0;

	int height1 = 4;
	int height2 = 5;

	int page1_max = 0;
	int page2_max = 0;
	int page3_max = 0;

	int trigger = FALSE;
	int p_trigger = FALSE;


	while (trigger != 2)
	{
		system("cls");
		BLUE
		Draw_Gotoxy.BoxDraw(0, 0, WIDTH, HEIGHT);
		ORIGINAL
		Draw_Gotoxy.gotoxy(WIDTH * 0.78, HEIGHT * 0.07);
		cout << "보유 Gold : " << cr_name->gold;
		Draw_Gotoxy.gotoxy(WIDTH * 0.8, HEIGHT * 0.07 + 2);
		cout << wp_name->weapon_type << " Shop";

		///// wp_name의 최대무기갯수를 먼저 구함 -> 반복문에서 각 page에 저장후 최대갯수 체크하고 break;

		for (int i = 0, j = 0, k = 0; i < wp_name->weapon_max_count;) //// 각페이지에 무기목록 저장
		{
			if (i + j + k == wp_name->weapon_max_count)
			{
				break;
			}
			if (i >= 0 && i <= 4)
			{
				tmp_page1[i].weapon_dmg = wp_name[i].weapon_dmg;
				tmp_page1[i].weapon_name = wp_name[i].weapon_name;
				tmp_page1[i].weapon_price = wp_name[i].weapon_price;
				tmp_page1[i].weapon_type = wp_name[i].weapon_type;
				i++;
				page1_max = i;
			}
			else if (i >= 5 && i <= 9)
			{
				tmp_page2[j].weapon_dmg = wp_name[i].weapon_dmg;
				tmp_page2[j].weapon_name = wp_name[i].weapon_name;
				tmp_page2[j].weapon_price = wp_name[i].weapon_price;
				tmp_page2[j].weapon_type = wp_name[i].weapon_type;
				j++;
				page2_max = j;
			}
			else if (i >= 10 && i <= 14)
			{
				tmp_page3[k].weapon_dmg = wp_name[i].weapon_dmg;
				tmp_page3[k].weapon_name = wp_name[i].weapon_name;
				tmp_page3[k].weapon_price = wp_name[i].weapon_price;
				tmp_page3[k].weapon_type = wp_name[i].weapon_type;
				k++;
				page3_max = k;
			}

		}


		if (trigger == FALSE)
		{
			Weapon_Show(tmp_page1, height1, height2, page1_max); // 1페이지
			select = Draw_Gotoxy.MenuSelectCursor(page1_max + 3, 3, WIDTH * 0.2, HEIGHT * 0.1 + 3); // 메뉴 선택
			trigger = Buy_Weapon(tmp_page1, cr_name, select, page1_max);
		}
		else if (trigger == TRUE && p_trigger == FALSE) // p_trigger는 3페이지를 위한 변수임
		{
			Weapon_Show(tmp_page2, height1, height2, page2_max); // 2페이지
			select = Draw_Gotoxy.MenuSelectCursor(page2_max + 3, 3, WIDTH * 0.2, HEIGHT * 0.1 + 3); // 메뉴 선택
			trigger = Buy_Weapon(tmp_page2, cr_name, select, page2_max);
			if (trigger == TRUE)
			{
				p_trigger = TRUE;
			}
		}
		else if (trigger == TRUE && p_trigger == TRUE)
		{
			Weapon_Show(tmp_page3, height1, height2, page3_max); // 3페이지
			select = Draw_Gotoxy.MenuSelectCursor(page3_max + 3, 3, WIDTH * 0.2, HEIGHT * 0.1 + 3); // 메뉴 선택
			trigger = Buy_Weapon(tmp_page3, cr_name, select, page3_max);
			if (trigger == FALSE)
			{
				trigger = TRUE;
				p_trigger = FALSE;
			}
		}
		else // 무기를 골랐을때 첫화면으로 돌아간다
		{
			trigger = FALSE;
		}
		select = 0;
	}

}

void Shop::Show_Shop(Character_Info *name)
{
	int select = 0;

	while (1)
	{
		BLUE
		Draw_Gotoxy.BoxDraw(0, 0, WIDTH, HEIGHT); // x시작점,y시작점,가로,세로
		ORIGINAL
		Draw_Gotoxy.DrawMidText("♧ ♣ S H O P ♧ ♣", WIDTH, HEIGHT * 0.3);
		Draw_Gotoxy.DrawMidText("Dagger", WIDTH, HEIGHT * 0.3 + 2);
		Draw_Gotoxy.DrawMidText("Gun", WIDTH, HEIGHT * 0.3 + 4);
		Draw_Gotoxy.DrawMidText("Sword", WIDTH, HEIGHT * 0.3 + 6);
		Draw_Gotoxy.DrawMidText("Wand", WIDTH, HEIGHT * 0.3 + 8);
		Draw_Gotoxy.DrawMidText("Bow", WIDTH, HEIGHT * 0.3 + 10);
		Draw_Gotoxy.DrawMidText("Hammer", WIDTH, HEIGHT * 0.3 + 12);
		Draw_Gotoxy.DrawMidText("돌아가기", WIDTH, HEIGHT * 0.3 + 14);

		select = Draw_Gotoxy.MenuSelectCursor(SHOP_MENU_COUNT, 2, WIDTH * 0.37, HEIGHT * 0.3 + 2);

		if (select == 1)
		{
			Weapon_Shop(Dagger, name);
		}
		else if (select == 2)
		{
			Weapon_Shop(Gun, name);
		}
		else if (select == 3)
		{
			Weapon_Shop(Sword, name);
		}
		else if (select == 4)
		{
			Weapon_Shop(Wand, name);
		}
		else if (select == 5)
		{
			Weapon_Shop(Bow, name);
		}
		else if (select == 6)
		{
			Weapon_Shop(Hammer, name);
		}
		else if (select == 7)
		{
			return;
		}
	}
}

Shop::~Shop()
{
	if (tmp_page1 != NULL)
	{
		delete[] tmp_page1;
		tmp_page1 = NULL;
	}
	if (tmp_page2 != NULL)
	{
		delete[] tmp_page2;
		tmp_page2 = NULL;
	}
	if (tmp_page3 != NULL)
	{
		delete[] tmp_page3;
		tmp_page3 = NULL;
	}


	if (Dagger != NULL)
	{
		delete[] Dagger;
		Dagger = NULL;
	}
	if (Gun != NULL)
	{
		delete[] Gun;
		Gun = NULL;
	}
	if (Sword != NULL)
	{
		delete[] Sword;
		Sword = NULL;
	}
	if (Wand != NULL)
	{
		delete[] Wand;
		Wand = NULL;
	}
	if (Bow != NULL)
	{
		delete[] Bow;
		Bow = NULL;
	}
	if (Hammer != NULL)
	{
		delete[] Hammer;
		Hammer = NULL;
	}
}
