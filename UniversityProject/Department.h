#pragma once
#include"Utils.h"



class Department
{
public:
	string deptName,deptCode;
	int maxStudents, maxTeachers;
	bool isActive;

	//Department();
	void handleManageDepartments();
	void splitDepartmentData(string line);
};

