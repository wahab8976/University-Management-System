#pragma once
#include "Utils.h"
#include "Person.h"
#include "CourseCollection.h"

class Admin : public Person
{
public:

	CourseCollection currentCourse;


	Admin(string name, string password, long long id, long  long phone, long long CNIC); // Accept these values if any Admin will login and its instance will be created with previous values
	~Admin();
	void showMenuMenu();
	void handleManageCourse();
	void handleManageStudents();



	void handleAddNewCourse();
};

