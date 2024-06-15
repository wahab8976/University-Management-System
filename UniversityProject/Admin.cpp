#include "Admin.h"
#include <iostream>


Admin::Admin(string name, string password, long long id, long long phone, long long CNIC)
{
    cout << "Admin is Created!" << endl;
    this->name = name;
    this->password = password;
    this->id = id;
    this->phone = phone;
    this->CNIC = CNIC;

}


Admin::~Admin() {
    cout << "Admin " << name << " is Deleted!" << endl;
}

void Admin::handleManageDepartments() {
    currentDept.loadDepartmentData();

    int choice = -1;
    do {
        cout << "1. View All Departments" << endl;
        cout << "2. Add New Department" << endl;
        cout << "3. Remove a Department" << endl;
        cout << "0. Back" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            currentDept.handleDisplayAllDepartment();
            break;
        case 2:
            currentDept.handleAddNewDepartment();
            break;
        case 3:
            // Implement remove department functionality
            break;
        default:
            cout << "Invalid Choice!" << endl;
            break;
        }
    } while (choice != 0);

    // Deleting Departments Dynamically after user chooses to exit
    for (int i = 0; i < currentDept.deptCount; i++)
    {
        delete currentDept.departmentColl[i];
    }
    currentDept.deptCount = 0; // Reset Department Count to 0 once all the depart,emts are deleted
    return;
}


void Admin::handleManageCourse()
{
    currentCourse.loadCourseData();
    int choice = -1;
    do {
        cout << "1. View all Courses" << endl;
        cout << "2. Add new Course" << endl;
        cout << "3. Remove a Course" << endl;
        cout << "4. Update a Course's record" << endl;
        cout << "5. Search a Course" << endl;
        cout << "0. Back" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            currentCourse.handleShowAllCourses();
            break;
        case 2:
            currentCourse.handleAddNewCourse();
            break;
        case 3:
            // Implement remove course functionality
            break;
        case 4:
            // Implement update course functionality
            break;
        case 5:
        {
            string tempCode = "";
            int responseIndex = -1;
            cin.ignore();
            cout << "Enter the Course Code: ";
            getline(cin, tempCode);
            responseIndex = currentCourse.handleCourseSearch(tempCode);
            if (responseIndex == -1)
            {
                cout << "Course Not Found" << endl;
                break;
            }
            currentCourse.getCourse(responseIndex);
        }
        break;
        default:
            cout << "Invalid Choice!" << endl;
            break;
        }
    } while (choice != 0);

    // Deleting Courses Dynamically after user chooses to exit
    for (int i = 0; i < currentCourse.courseCount; i++)
    {
        delete currentCourse.courseColl[i];
    }
    currentCourse.courseCount = 0; // Reset course Count to 0 to ensure proper check for next time
    return;
}



void Admin::handleManageStudents() {
    int choice = -1;
    do {
        cout << "1. View all Students" << endl;
        cout << "2. Add new Student" << endl;
        cout << "3. Remove a Student" << endl;
        cout << "4. Update a Student's record" << endl;
        cout << "0. Back" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            // Implement view all students functionality
            break;
        case 2:
            // Implement add new student functionality
            break;
        case 3:
            // Implement remove student functionality
            break;
        case 4:
            // Implement update student record functionality
            break;
        default:
            cout << "Invalid Choice!" << endl;
            break;
        }
    } while (choice != 0);
}

void Admin::showMenuMenu() {
    int choice = -1;
    cout << "Welcome Back! " << name << endl;

    do {
        cout << "========================================" << endl;
        cout << "1. Manage Teachers" << endl;
        cout << "2. Manage Students" << endl;
        cout << "3. Manage Courses" << endl;
        cout << "4. Manage Departments" << endl;
        cout << "0. Exit" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Implement manage teachers functionality
            break;
        case 2:
            handleManageStudents();
            break;
        case 3:
            handleManageCourse();
            break;
        case 4:
            handleManageDepartments();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
            break;
        }

    } while (choice != 0);
}
