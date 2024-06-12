#include "Course.h"
#include"Utils.h"

void Course::setCourseName(string tempCourseName)
{
	courseName = tempCourseName;
	cout << "Course Name: " << courseName << endl;
}


void Course::writeCourseData()
{
	ofstream writer("CourseData.txt");
	for (int i =0 ;i <5;i++)
	{
		
	}
	writer.close();
}