#pragma once
#include "Utils.h"
#include"Course.h"
#include"person.h"
#include"Department.h"
#include "CourseCollection.h"

class Teacher:public Person
{
public:
	jobTitle title;
	CourseCollection* courseTeaching; // Indicates the collection of courses  a teacher can teach
	int attendPercent;
	bool presentToday;
	float salary;
	bool isPaid;
	Department* teacherDept;	// Indicates to which department the teacher belongs to

	Teacher();

	void  writeTeacherData();

};

