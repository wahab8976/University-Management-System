#include "Department.h"
#include "Utils.h"


Department::~Department()
{
	cout << "Department is Destroyed!" << endl;
}

Department::Department()
{
	//cout << "Department is Created!" << endl;
	cout << "Def  Constructor" << endl;
}

// Takes values when update Fn runs
Department::Department(string newCode, string  newName, bool setActive,int  newMaxTeach, int newMaxSt)
{
	//cout << "Department is Created!" << endl;
	deptCode = newCode;
	deptName = newName;
	isActive = setActive;
	maxStudents = newMaxSt;
	maxTeachers = newMaxTeach;
	cout << "Department is Created SuccessFully!" << endl;
}





void Department::setDeptCode(string code)
{
	deptCode = code;
	cout << "Course Code Added" << endl;
	return;
}


void Department::setDeptName(string name)
{
	deptName = name;
	cout << "Course Name Added" << endl;
	return;
}


void Department::setMaxStud(int maxSt)
{
	maxStudents = maxSt;
	cout << "Maximum Students Added" << endl;
	return;
}


void Department::setMaxTeach(int maxTeach)
{
	maxTeachers = maxTeach;
	cout << "Maximum Teachers Added" << endl;
	return;
}


void Department::setActivity(bool setActive)
{
	isActive = setActive;
	return;

}

void Department::writeDepartmentData()
{
	ofstream writer("DepartmentData.txt",ios::app);


	writer << deptCode << "," << deptName << "," << isActive << "," << maxStudents << "," << maxTeachers << endl;

	writer.close();

}



void Department::splitDepartmentData(string line) {

	// Extract department code
	size_t pos = line.find(",");
	string token = line.substr(0, pos);
	deptCode = token;
	line.erase(0, pos + 1);

	// Extract department name
	pos = line.find(",");
	token = line.substr(0, pos);
	deptName = token;
	line.erase(0, pos + 1);

	// Extract active status
	pos = line.find(",");
	token = line.substr(0, pos);
	isActive = stoi(token);
	line.erase(0, pos + 1);

	// Extract max students
	pos = line.find(",");
	token = line.substr(0, pos);
	maxStudents = stoi(token);
	line.erase(0, pos + 1);

	// Extract max teachers (remaining line)
	maxTeachers = stoi(line);
}