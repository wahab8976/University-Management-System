#pragma once
#include"Utilites.h"
#include"Person.h"

class PersonCollection
{
public:
	Person* PersonColl[100];
	int personCount;

	PersonCollection();

	void loadPersonData();

};
