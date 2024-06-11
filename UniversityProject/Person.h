#pragma once
#include "Utilites.h"

class Person
{
public:
	string name, password;
	long long id, CNIC;
	Role personType;

	Person();

	void splitPersonData(string  line);
};

