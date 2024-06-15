#include "DepartmentCollection.h"
#include "Utils.h"


void DepartmentCollection::handleDisplayAllDepartment() 
{
    if (deptCount == 0) 
    {
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
        cout << setw(deptNameWidth) << departmentColl[i]->deptName
            << setw(deptCodeWidth) << departmentColl[i]->deptCode
            << setw(otherColWidth) << (departmentColl[i]->isActive ? "Yes" : "No")
            << setw(otherColWidth) << departmentColl[i]->maxStudents
            << setw(otherColWidth) << departmentColl[i]->maxTeachers << endl;
    }
    cout << endl;
}




DepartmentCollection::DepartmentCollection()
{
    deptCount = 0;
}



void DepartmentCollection::getDept(int index)
{
    const int deptCodeWidth = 20; // Width for department code
    const int deptNameWidth = 40; // Wider column for department name
    const int otherColWidth = 20; // Width for other columns

    // Table Header
    cout << left << setw(deptCodeWidth) << "Department Code"
        << setw(deptNameWidth) << "Department Name"
        << setw(otherColWidth) << "Active"
        << setw(otherColWidth) << "Faculty Count"
        << setw(otherColWidth) << "Student Count" << endl;

    // Separator line
    cout << left << setw(deptCodeWidth) << "--------------------"
        << setw(deptNameWidth) << "----------------------------------------"
        << setw(otherColWidth) << "--------------------"
        << setw(otherColWidth) << "--------------------"
        << setw(otherColWidth) << "--------------------" << endl;

    // Table Row
    cout << setw(deptCodeWidth) << departmentColl[index]->deptCode
        << setw(deptNameWidth) << departmentColl[index]->deptName
        << setw(otherColWidth) << (departmentColl[index]->isActive ? "Yes" : "No")
        << setw(otherColWidth) << departmentColl[index]->maxTeachers
        << setw(otherColWidth) << departmentColl[index]->maxStudents << endl;

    cout << endl;
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
        departmentColl[deptCount] = new Department();
        departmentColl[deptCount]->splitDepartmentData(line);
        deptCount++;
    }

    reader.close();
}


void DepartmentCollection::handleAddNewDepartment()
{
    int maxSt, maxTch;
    cin.ignore();

    departmentColl[deptCount] = new Department();
    cout << "Enter course name:" << endl;
    string tempName;
    getline(cin, tempName);
    departmentColl[deptCount]->setDeptName(tempName);


    cout << "Enter course code:" << endl;
    string tempCode;
    getline(cin, tempCode);
    departmentColl[deptCount]->setDeptCode(tempCode);


    cout << "Enter Maximum number of Students" << endl;
    cin >> maxSt;
    departmentColl[deptCount]->setMaxStud(maxSt);

    cout << "Enter Maximum number of Teachers" << endl;
    cin >> maxTch;
    departmentColl[deptCount]->setMaxTeach(maxTch);


    departmentColl[deptCount]->writeDepartmentData();
    deptCount++;
}


int DepartmentCollection::handleSearchDepartment(string code)
{
    bool deptFound = false;
    int foundDeptIndex = -1;

    for (int i = 0; i < deptCount; i++)
    {
        if (departmentColl[i] != nullptr && code == departmentColl[i]->deptCode)
        {
            deptFound = true;
            foundDeptIndex = i;
            break;
        }
    }

    if (!deptFound)
    {
        return -1; // Return -1 if course not matched for conditional matching
    }
    else
    {
        return foundDeptIndex;
    }
}