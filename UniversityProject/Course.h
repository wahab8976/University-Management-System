#pragma once
#include "Utils.h"
class Course
{
	string  courseName, courseCode;
	bool isAvailable;
	int studentCount, teacherCount;
public:
	void setCourseName(string tempCourseName);
	void writeCourseData();
};

