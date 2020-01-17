#include "Computer.h"

#pragma once


void main()
{
	int num = 0;

	Login log;
	Computer com;
	
	while (1)
	{
		com.Menu(); // login에서만들걸 그냥  전부 com으로 쓰기
		if (com.exit == TRUE)
		{
			break;
		}
		com.Change_Login_Status(num); // com에서 쓸수없는것은 별개값을 들고있어서임
		com.Menu2();
	}

}