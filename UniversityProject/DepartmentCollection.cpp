#include "DepartmentCollection.h"
#include "Utils.h"



void DepartmentCollection::handleDisplayAllDepartment() {
    if (deptCount == 0) {
        cout << "No departments to show." << endl;
        return;
    }

    cout << "Total Departments: " << deptCount << endl;

    const int deptNameWidth = 30;   // Column width for department name
    const int deptCodeWidth = 10;   // Column width for department code
    const int otherColWidth = 15;   // Column width for other columns

    // Table Header
    cout << left << setw(deptNameWidth) << "Department Name"
        << setw(deptCodeWidth) << "Dept Code"
        << setw(otherColWidth) << "Active"
        << setw(otherColWidth) << "Max Students"
        << setw(otherColWidth) << "Max Teachers" << endl;

    // Separator line
    cout << left << setw(deptNameWidth) << "------------------------------"
        << setw(deptCodeWidth) << "----------"
        << setw(otherColWidth) << "---------------"
        << setw(otherColWidth) << "---------------"
        << setw(otherColWidth) << "---------------" << endl;

    // Table Rows
    for (int i = 0; i < deptCount; i++) {
        cout << setw(deptNameWidth) << departmentColl[i].deptName
            << setw(deptCodeWidth) << departmentColl[i].deptCode
            << setw(otherColWidth) << (departmentColl[i].isActive ? "Yes" : "No")
            << setw(otherColWidth) << departmentColl[i].maxStudents
            << setw(otherColWidth) << departmentColl[i].maxTeachers << endl;
    }
    cout << endl;
}



/*


void DepartmentCollection::writeDepartmentData()
{
    ofstream writer("DepartmentData.txt");

    departmentColl[0].deptName = "Computer Science";
    departmentColl[0].deptCode = "CS";
    departmentColl[0].isActive = 1;
    departmentColl[0].maxStudents = 1000;
    departmentColl[0].maxTeachers = 20;

    // Dummy initialization for other departments
    departmentColl[1].deptName = "Electrical Engineering";
    departmentColl[1].deptCode = "EE";
    departmentColl[1].isActive = 1;
    departmentColl[1].maxStudents = 800;
    departmentColl[1].maxTeachers = 15;

    departmentColl[2].deptName = "Mechanical Engineering";
    departmentColl[2].deptCode = "ME";
    departmentColl[2].isActive = 0;
    departmentColl[2].maxStudents = 900;
    departmentColl[2].maxTeachers = 18;

    departmentColl[3].deptName = "Physics";
    departmentColl[3].deptCode = "PHY";
    departmentColl[3].isActive = 0;
    departmentColl[3].maxStudents = 500;
    departmentColl[3].maxTeachers = 10;

    departmentColl[4].deptName = "Mathematics";
    departmentColl[4].deptCode = "MATH";
    departmentColl[4].isActive = 1;
    departmentColl[4].maxStudents = 700;
    departmentColl[4].maxTeachers = 12;


    for (int i = 0; i < 5; i++)
    {
        cout << "Writingg" << endl;
        writer << departmentColl[i].deptCode << "," << departmentColl[i].deptName << "," << departmentColl[i].isActive << "," << departmentColl[i].maxStudents << "," << departmentColl[i].maxTeachers << endl;
    }

    writer.close();
}


*/


DepartmentCollection::DepartmentCollection()
{
    deptCount = 0;
}


void DepartmentCollection::loadDepartmentData()
{
    ifstream reader("DepartmentData.txt");

    if (!reader.is_open())
    {
        cout << "Error opening in file" << endl;
        return;
    }


    string line = "";

    while (getline(reader,line))
    {
        departmentColl[deptCount].splitDepartmentData(line);
        deptCount++;
    }

    reader.close();
}






void DepartmentCollection::handleAddNewDepartment()
{
	string tempName, tempCode;
	cin.ignore();
	cout << "Enter Name of Department:" << endl;
	getline(cin, tempName);

	cout << "Enter code of Department:" << endl;
	getline(cin, tempCode);


	//departmentColl[0]->writeDepartmentData();

}
/*


void DepartmentCollection::writeDepartmentData()
{

    departmentColl[0]->deptName = "Computer Science";
    departmentColl[0]->deptCode = "CS";
    departmentColl[0]->isActive = true;
    departmentColl[0]->maxStudents = 1000;
    departmentColl[0]->maxTeachers = 20;

    departmentColl[1]->deptName = "Electrical Engineering";
    departmentColl[1]->deptCode = "EE";
    departmentColl[1]->isActive = true;
    departmentColl[1]->maxStudents = 800;
    departmentColl[1]->maxTeachers = 15;

    departmentColl[2]->deptName = "Mechanical Engineering";
    departmentColl[2]->deptCode = "ME";
    departmentColl[2]->isActive = true;
    departmentColl[2]->maxStudents = 900;
    departmentColl[2]->maxTeachers = 18;

    departmentColl[3]->deptName = "Physics";
    departmentColl[3]->deptCode = "PHY";
    departmentColl[3]->isActive = false;
    departmentColl[3]->maxStudents = 500;
    departmentColl[3]->maxTeachers = 10;

    departmentColl[4]->deptName = "Mathematics";
    departmentColl[4]->deptCode = "MATH";
    departmentColl[4]->isActive = true;
    departmentColl[4]->maxStudents = 700;
    departmentColl[4]->maxTeachers = 12;

    ofstream writer("DepartmentData.txt");

    for (int i =0 ; i < 5;i++)
    {
        writer<<departmentColl[i]->deptCode<<","<< departmentColl[i]->deptName<<","<< departmentColl[i]->isActive<<","<< departmentColl[i]->maxStudents<<","<< departmentColl[i]->maxTeachers<<endl;
    }
    writer.close();

}


*/

