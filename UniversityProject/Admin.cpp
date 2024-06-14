#include "Admin.h"
#include "Course.h"
#include "CourseCollection.h"
#include <iomanip>


Admin::Admin(string name, string password, long long id, long long phone, long long CNIC) {
	cout << "Admin is Created!" << endl;
	this->name = name;
	this->password = password;
	this->id = id;
	this->phone = phone;
	this->CNIC = CNIC;

}

void Admin::handleShowAllCourses()
{
	if (currentCourse.courseCount == 0)
	{
		cout << "No courses  to show" << endl;
		return;
	}

	cout << "Total Courses: " << currentCourse.courseCount << endl;

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
	for (int i = 0; i < currentCourse.courseCount; i++)
	{
		
		cout << setw(courseNameWidth) << currentCourse.courseColl[i].courseCode
			<< setw(courseCodeWidth) << currentCourse.courseColl[i].courseName
			<< setw(otherColWidth) << currentCourse.courseColl[i].teacherCount ;

		//Checking if course is not available then show students count as --
		if (currentCourse.courseColl[i].isAvailable)
		{
			cout << setw(otherColWidth) << currentCourse.courseColl[i].studentCount;
		}
		else
		{
			cout << setw(otherColWidth) << "-- ";
		}
		cout<< setw(otherColWidth) << (currentCourse.courseColl[i].isAvailable ? "Yes" : "No") << endl;
	}
	cout << endl;
}


Admin::~Admin()
{
	cout << "Admin is  Deleted!" << endl;
}

void Admin::handleAddNewCourse()
{
	

}

void Admin::handleManageCourse()
{
	currentCourse.loadCourseData();

	int choice = -1;
	do
	{
		cout << "1. View all Courses" << endl;
		cout << "2. Add new Course" << endl;
		cout << "3. Remove a Course" << endl;
		cout << "4. Update a Course's record" << endl;
		cout << "0. Back" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			handleShowAllCourses();
			break;
		case 2:
			handleAddNewCourse();
		default:
			break;
		}
	} while (choice != 0);

	
}

void  Admin::handleManageStudents()
{
	int choice = -1;
	do
	{
		cout << "1. View all Students" << endl;
		cout << "2. Add new Student" << endl;
		cout << "3. Remove a Student" << endl;
		cout << "4. Update a Student's record" << endl;
		cout << "0. Back" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			
			break;
		default:
			break;
		}

	} while (choice != 0);

	

}


void Admin::showMenuMenu()
{
	int choice = -1;
	cout << "Welcome Back! " << name << endl;

	do
	{
		cout << "========================================" << endl;
		cout << "========================================" << endl;
		cout << "1. Manage Teachers" << endl;
		cout << "2. Manage Students" << endl;
		cout << "3. Manage Courses" << endl;
		cout << "4. Manage Departments" << endl;
		cout << "0. Exit" << endl;

		cout << "========================================" << endl;
		cout << "========================================" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			break;
		case 2:
			handleManageStudents();
			break;
		case 3:
			handleManageCourse();
			break;
		case 4:
			break;
		default:
			cout << "Invalid Choice!" << endl;
			break;
		}

	} while (choice != 0);





}