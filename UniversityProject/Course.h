#pragma once
#include "Utils.h"
class Course
{
public:
	string  courseName, courseCode;
	bool isAvailable;
	int studentCount, teacherCount;

	Course();
	Course(string code,string name,bool setActive);
	~Course();
	
	void splitCardData(string line);
	void writeCourseData();
	void setCourseName(string name);
	void setCourseCode(string code);
	void setActivity(bool  setActive);
};

