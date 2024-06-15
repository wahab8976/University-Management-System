#pragma once
#include "Utils.h"
#include"Department.h"

class DepartmentCollection
{
public:
	Department* departmentColl[100];
	int deptCount;


	DepartmentCollection();
	void loadDepartmentData();
	void handleAddNewDepartment();
	void handleDisplayAllDepartment();
	//void writeDepartmentData();
};

