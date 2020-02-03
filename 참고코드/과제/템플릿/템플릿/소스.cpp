#include <iostream>
#include <time.h>
#include <Windows.h>
#include <string>
#include<conio.h> // getch()
using namespace std;

template<typename Type>
void Add(Type num)
{
	cout << "변경 전 : " << num << endl;
	num++;
	cout << "변경 후 : " << num << endl;
}

template<typename Type>
Type Big(Type num, Type num2)
{
	if (num > num2)
		return num2;
	else
		return num;
}

template<typename Test>
Test Max(Test num, Test num2, Test num3)
{
	if (num > num2)
	{
		if (num > num3)
			return num;
		else
			return num3;
	}

	else if (num2 > num)
	{
		if (num2 > num3)
			return num2;
		else
			return num3;
	}
}

void main()
{
	int num, num2, num3;

	cout << "숫자를 입력하세요 : ";
	cin >> num;
	Add(num);

	cout << "두 숫자를 입력하세요 : ";
	cin >> num >> num2;
	cout << "둘중에 작은수는 : " << Big(num, num2) << endl;

	cout << "숫자 세개를 입력하세요";
	cin >> num >> num2 >> num3;
	cout << "셋중에 가장 큰 수는 : " << Max(num, num2, num3) << endl;


	system("pause");
}