#include "CourseCollection.h"
#include "Utils.h"
#include "Course.h"


CourseCollection::CourseCollection()
{
	courseCount = 0;
	cout << "Card Collection created..." << endl;
	
}

CourseCollection::~CourseCollection()
{
	for (int i = 0; i < courseCount; i++) {
		delete courseColl[i];
	}
	cout << "Course Collection destroyed..." << endl;
}


void CourseCollection::handleAddNewCourse()
{
	cout << "Length of Array: " << courseCount << endl;
	//int tempLength = 0;
	string tempName, tempCode = "";



	cin.ignore();
	courseColl[courseCount + 1] = new Course(); 

	//cout << "Enter data for course " << i + 1 << endl;
	cout << "Enter course name:" << endl;
	getline(cin, tempName);
	courseColl[courseCount + 1]->setCourseName(tempName);

	cout << "Enter course code: ";
	getline(cin, tempCode);
	courseColl[courseCount + 1]->setCourseCode(tempCode);

	courseColl[courseCount + 1]->writeCourseData();
	courseCount++;

}


void CourseCollection::loadCourseData()
{
	ifstream reader("CourseData.txt");

	if (!reader.is_open())
	{
		cout << "Error opening course data" << endl;
		return;
	}
	else
	{
		string line = "";
		while (getline(reader, line))
		{
			courseColl[courseCount] = new Course();
			courseColl[courseCount]->splitCardData(line);
			courseCount++;
		}
	}


}



void CourseCollection::handleShowAllCourses()
{
	if (courseCount == 0)
	{
		cout << "No courses  to show" << endl;
		return;
	}

	cout << "Total Courses: " << courseCount << endl;

	const int courseNameWidth = 40; // Wider column for course name
	const int courseCodeWidth = 30; // Adjusted width for course code
	const int otherColWidth = 20; // Width for other columns

	// Table Header
	cout << left << setw(courseNameWidth) << "Course Name"
		<< setw(courseCodeWidth) << "Course Code"
		<< setw(otherColWidth) << "Teachers Available"
		<< setw(otherColWidth) << "Students Enrolled"
		<< setw(otherColWidth) << "Available?" << endl;

	// Separator line
	cout << left << setw(courseNameWidth) << "----------------------------------------"
		<< setw(courseCodeWidth) << "------------------------------"
		<< setw(otherColWidth) << "--------------------"
		<< setw(otherColWidth) << "--------------------"
		<< setw(otherColWidth) << "--------------------" << endl;

	// Table Rows
	for (int i = 0; i < courseCount; i++)
	{

		cout << setw(courseNameWidth) << courseColl[i]->courseCode
			<< setw(courseCodeWidth) << courseColl[i]->courseName
			<< setw(otherColWidth) << courseColl[i]->teacherCount;

		//Checking if course is not available then show students count as --
		if (courseColl[i]->isAvailable)
		{
			cout << setw(otherColWidth) << courseColl[i]->studentCount;
		}
		else
		{
			cout << setw(otherColWidth) << "-- ";
		}
		cout << setw(otherColWidth) << (courseColl[i]->isAvailable ? "Yes" : "No") << endl;
	}
	cout << endl;
}