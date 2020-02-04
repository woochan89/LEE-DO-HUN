#include <iostream>
#include<Windows.h>
#include<string>
#include<time.h>
#include<conio.h> // getch()
using namespace std;

class Time
{
private:
	int second;
	int min;
	int hour;
public:
	Time()
	{
		second = 0;
		min = 0;
		hour = 0;
	}

	int Getsecond()
	{
		return second;
	}
	void operator++()
	{
		++second;
	}
	void operator--()
	{
		--second;
	}
	void ShowTime()
	{
		system("cls");
		cout << hour << "시   " << min << "분   " << second << "초" << endl;
	}

	Time operator+(Time tmp);
};

Time Time::operator+(Time tmp) // 객체 + 객체
{
	this->second += tmp.second; //this는 자기자신, 즉 t1

	if (this->second == 60)
	{
		this->min++;
		this->second = 0;
	}
	if (this->min == 60)
	{
		this->hour++;
		this->min = 0;
	}
	return tmp;
}

void main()
{
	Time t1, t2;

	while (1)
	{
		Sleep(10);
		++t2;
		t1 + t2; // t2는 객체 + 객체의 형태를 위해서 사용함
		--t2;
		t1.ShowTime();
	}

}