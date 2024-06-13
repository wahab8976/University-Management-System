#pragma once
#include "Utils.h"
class Course
{
public:
	string  courseName, courseCode;
	bool isAvailable;
	int studentCount, teacherCount;

	Course();

	void setCourseName(string tempCourseName);
	void splitCardData(string line);
	//void writeCourseData();
};

