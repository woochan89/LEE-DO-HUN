#include "Ward.h"
#pragma once

#define WARD_MAX 75

class WardManager : virtual public Ward
{
private:
public:
	WardManager();
	void Load_Ward(_Ward *name, int ward_max);
	void Set_xy(_Ward *name);
	~WardManager();
};

