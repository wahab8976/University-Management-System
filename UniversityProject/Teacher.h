#pragma once
#include "Utils.h"
#include"Course.h"
#include"person.h"

class Teacher:public Person
{
public:
	jobTitle title;
	courseAvailable courseTeaching;  // to be converted to pointer in future
	int attendPercent;
	bool presentToday;
	float salary;
	bool isPaid;
	
	Teacher();

	void  writeTeacherData();

};

