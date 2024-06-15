#pragma once
#include"Utils.h"

class Department
{
public:
	string deptName,deptCode;
	int maxStudents, maxTeachers;
	bool isActive;

	Department();
	Department(string newCode, string  newName, bool setActive, int  newMaxTeach, int newMaxSt);
	~Department();

	void splitDepartmentData(string line);
	void setDeptName(string name);
	void setDeptCode(string code);
	void setMaxStud(int st);
	void setMaxTeach(int tch);
	void setActivity(bool setActive);
	void writeDepartmentData();


};

