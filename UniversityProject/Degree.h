#pragma once
#include<string>
#include"Utils.h"
#include"Department.h"

using namespace std;


class Degree
{
	DegreeType program;
	string name;
	Department* offeredInDept;
	int duration;

public:
	Degree();

};

