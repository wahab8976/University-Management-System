#pragma once
#include "Utils.h"
#include "Person.h"

class Admin : public Person
{
public:
	void showMenuMenu();
	void handleManageCourse();
	void handleManageStudents();



	void handleAddNewCourse();
};

