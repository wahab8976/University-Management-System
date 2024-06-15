#pragma once
#include"Utils.h"

class Department
{
public:
	string deptName,deptCode;
	int maxStudents, maxTeachers;
	bool isActive;

	Department();
	~Department();

	void splitDepartmentData(string line);
	void setDeptName(string name);
	void setDeptCode(string code);
	void setMaxStud(int st);
	void setMaxTeach(int tch);
	void setActivity(bool setActive);
	void writeDepartmentData();


};

