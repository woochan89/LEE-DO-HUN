#pragma once
#include "Person.h"

class Student : public School, public Person
{
public:
	void Input();
	void Show();
	Student();
	~Student();
};

