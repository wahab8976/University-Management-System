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
    //Extract course Name
    size_t pos = line.find(",");
    string token = line.substr(0, pos);
    courseName = token;
    line.erase(0, pos + 1);

    pos = line.find(",");
    token = line.substr(0, pos);
    courseCode = token;
    line.erase(0, pos + 1);

    // Extract availability
    pos = line.find(",");
    token = line.substr(0, pos);
    isAvailable = stoi(token);
    line.erase(0, pos + 1);

    // Extract student count
    pos = line.find(",");
    token = line.substr(0, pos);
    studentCount = stoi(token);
    line.erase(0, pos + 1);

    // Extract teacher count
    teacherCount = stoi(line); // Remaining line is the teacher count
}

void Course::setCourseName(string tempCourseName)
{
	courseName = tempCourseName;
	cout << "Course Name: " << courseName << endl;
}

