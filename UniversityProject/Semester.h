#pragma once
#include"Course.h"
#include"Subject.h"
#define MAX_COURSES 8

class Semester
{
	int num;
	Course* coursesEnrolled[MAX_COURSES];
	Subject* subjectStudying[MAX_COURSES];
};

