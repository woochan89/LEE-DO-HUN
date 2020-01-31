#pragma once
#include"Weapon.h"
#include"MapDraw.h"
#include"Character.h"

#define SHOP_MENU_COUNT 7

class Shop : virtual public Weapon, virtual public Character
{
protected:
	Weapon_Info *wp;
	Weapon_Info *tmp_page1, *tmp_page2, *tmp_page3;

	Weapon_Info *Dagger;
	Weapon_Info *Gun;
	Weapon_Info *Sword;
	Weapon_Info *Wand;
	Weapon_Info *Bow;
	Weapon_Info *Hammer;

	MapDraw Draw_Gotoxy;
public:
	void Init_Weapon();
	void Show_Shop(Character_Info *name);
	int Create_Weapon(string name);
	void Create_Weapon2(string name, Weapon_Info *wp_name);
	void Weapon_Shop(Weapon_Info *wp_name, Character_Info *cr_name);
	void Weapon_Show(Weapon_Info *wp_name, int ht1, int ht2, int num);
	int Buy_Weapon(Weapon_Info *wp_name, Character_Info *cr_name, int select_menu, int page);
	Shop();
	~Shop();
};

