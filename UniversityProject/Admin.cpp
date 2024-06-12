#include "Admin.h"



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
			break;
		case 4:
			break;
		default:
			cout << "Invalid Choice!" << endl;
			break;
		}

	} while (choice != 0);





}