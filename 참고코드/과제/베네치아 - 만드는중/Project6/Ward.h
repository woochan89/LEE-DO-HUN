#include "Mecro.h"
#pragma once

struct _Ward
{
	string name;
	int x;
	int y;
	int status; // 단어가 죽었는지 살았는지 구별하기위해 필요
};

class Ward
{
private:
public:
	Ward();


	~Ward();
};

