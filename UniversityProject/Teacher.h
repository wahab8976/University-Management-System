#pragma once
#include "Utils.h"
#include"Course.h"
#include"person.h"

class Teacher:public Person
{
	jobTitle title;
	Course* courseTeaching;
	int attendPercent;
	bool presentToday;
	float salary;
	bool isPaid;
	
};

