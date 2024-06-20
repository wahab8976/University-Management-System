#include "Teacher.h"
#include  "Utils.h"

Teacher::Teacher()
{
	cout << "Teacher is Created!" << endl;
}

void Teacher::writeTeacherData()
{
	Teacher teacher[10];
    
	ofstream writer("TeacherData.txt");



	writer.close();
}