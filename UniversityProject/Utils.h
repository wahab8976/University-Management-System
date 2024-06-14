#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<iomanip>
using namespace std;


enum jobTitle
{
	PROFESSOR = 1,
	LECTURER,
	VC
};

/*
enum deptAvailable
{
	CS = 1,
	IT,
	SE
};

*/
/*
enum courseAvailable
{
	webTech = 1,
	appDev,
	desktopDev,
	AI,
	ML
};

*/


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

