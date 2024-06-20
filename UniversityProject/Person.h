#pragma once
#include "Utils.h"

class Person
{
public:
	string name, password, address, email;
	long long id, CNIC, phone;
	Role personType;
	Gender  gndr;

	void splitPersonData(string  line);
};

