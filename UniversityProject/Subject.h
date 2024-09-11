#pragma once
#include<iostream>
#include<fstream>
#include"Teacher.h"
using namespace std;
class Subject
{
	int credits;
	string name;
	int marks,attendance;
	Teacher* teachedBy;
	
public:
	Subject();
};

