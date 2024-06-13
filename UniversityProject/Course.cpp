#include "Course.h"
#include"Utils.h"



Course::Course()
{
	cout << "Course is  created" << endl;
}



/*
void Course::writeCourseData()
{


    ofstream writer("CourseData.txt");
    for (int i = 0; i < 4; i++)
    {
        writer << coursetowrite[i].courseCode << "," << coursetowrite[i].courseName << "," << coursetowrite[i].isAvailable << "," << coursetowrite[i].studentCount << "," << coursetowrite[i].teacherCount << endl;
    }

    writer.close();


}

*/



void Course::splitCardData(string line)
{
	cout << "Spliting....." << endl;
}

void Course::setCourseName(string tempCourseName)
{
	courseName = tempCourseName;
	cout << "Course Name: " << courseName << endl;
}

