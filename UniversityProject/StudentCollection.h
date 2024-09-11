#pragma once
#include "Student.h"

class StudentCollection
{
	Student* studentColl[100];
	int studentCount;

	StudentCollection();
	void loadStudentsData();
};

