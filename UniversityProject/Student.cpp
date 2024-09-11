#include "Student.h"


Student::Student()
{
	cout << "Student is created!" << endl;
}

//Will start from here tomorrow by adding sample data in the form of Array
void Student::writeStudentData(Student& student)
{
	ifstream writer("StudentData.txt");
	if (!writer.is_open())
	{
		cout << "Error in opening the file" << endl;
		return;
	}


	writer.close();
}