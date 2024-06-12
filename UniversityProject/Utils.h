#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;











class Utility
{
public:
	static long long getNumericInput(int length);
};

enum Gender
{
	FEMALE = 0,
	MALE
};

enum Role
{
	ADMIN = 1,
	TEACHER,
	STUDENT
};

