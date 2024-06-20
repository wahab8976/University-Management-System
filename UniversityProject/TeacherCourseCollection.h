#pragma once
#include "Teacher.h"
#include "CourseCollection.h"
#include "Utils.h"

class TeacherCourseCollection
{
public:
	Teacher currentTeacher;
	CourseCollection currentCourses[6];
	int minCourses, maxCourses;

	void writeTeacherCourses();
};

