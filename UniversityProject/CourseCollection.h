#pragma once
#include "Utils.h"
#include "Course.h"


class CourseCollection
{
public:
	Course* courseColl[100];
	int studentCount, teacherCount, courseCount;
	CourseCollection();
	~CourseCollection();


	void loadCourseData();
	void handleAddNewCourse();
	void handleShowAllCourses();
	void handleAddDeleteCourse();

	int handleCourseSearch(string code);
	void  getCourse(int index);
};

