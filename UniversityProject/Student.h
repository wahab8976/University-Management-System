#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Department.h"
#include"Course.h"
#include"Person.h"
#include"Degree.h"
#include"CourseCollection.h"
#include"Semester.h"
#include"Degree.h"

class Student:public Person
{
	Degree program;
	Semester currentSemester;

public:
	Student();
	void writeStudentData(Student& student);
};

