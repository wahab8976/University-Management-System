#include "Course.h"
#include"Utils.h"



Course::Course()
{
	cout << "Course is  created" << endl;
}

Course::Course(string code, string name, bool setActive)
{
	courseCode = code;
	courseName = name;
	isAvailable = setActive;
	studentCount = 0;
	teacherCount = 0;
	cout << "Record Addded SuccessFully" << endl;
}


Course::~Course()
{
	cout << "Course is  Destroyed" << endl;
}


void Course::setActivity(bool setActive)
{
	isAvailable = setActive;
	cout << "Activity Status  Added" << endl;
	return;
}

void Course::setCourseCode(string code)
{
	courseCode = code;
	cout << "Course code added" << endl;
	return;
}

void Course::setCourseName(string name)
{

	courseName = name;
	cout << "Course name added" << endl;
	return;
}

void Course::writeCourseData()
{
	cout << "Writing Data" << endl;
	ofstream writer("CourseData.txt", ios::app);

	if (!writer) {
		cout << "Error: Unable to open file for writing." << endl;
		return;
	}

	isAvailable = 1;
	studentCount = 0;
	teacherCount = 0;
	writer << courseCode << "," << courseName << "," << isAvailable << "," << studentCount << "," << teacherCount << endl;

	
	cout << "Data Added Successfully" << endl;
	
}



void Course::splitCardData(string line)
{
	//Extract course Name
	size_t pos = line.find(",");
	string token = line.substr(0, pos);
	courseCode = token;
	line.erase(0, pos + 1);

	pos = line.find(",");
	token = line.substr(0, pos);
	courseName = token;
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


