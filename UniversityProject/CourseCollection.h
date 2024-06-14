#pragma once
#include "Utils.h"
#include "Course.h"


class CourseCollection
{
public:
	Course* courseColl[20];
	int studentCount, teacherCount, courseCount;
	CourseCollection();
	~CourseCollection();


	void loadCourseData();
	void handleAddNewCourse();
	void handleShowAllCourses();
};

