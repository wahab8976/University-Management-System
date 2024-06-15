#include "CourseCollection.h"
#include "Utils.h"
#include "Course.h"


CourseCollection::CourseCollection() 
{
    courseCount = 0;
    cout << "Card Collection created..." << endl;
}

CourseCollection::~CourseCollection() 
{
    for (int i = 0; i < courseCount; i++) 
    {
        delete courseColl[i];
    }
    cout << "Course Collection destroyed..." << endl;
}



void CourseCollection::handleUpDateCourse()
{
    cin.ignore();
    string code;

    cout << "Enter Course Code: ";
    getline(cin, code);

    int responseIndex = handleCourseSearch(code);
    if (responseIndex == -1)
    {
        cout << "Course not Found" << endl;
        return;
    }

    string newName, newCode;
    int newStudentCount, newTeacherCount;
    bool newIsAvailable;

    cout << "Enter new Course Name: ";
    getline(cin, newName);

    cout << "Enter new Course Code: ";
    getline(cin, newCode);

    cout << "Enter new Student Count: ";
    cin >> newStudentCount;
    cin.ignore();

    cout << "Enter new Teacher Count: ";
    cin >> newTeacherCount;
    cin.ignore();

    while (true)
    {
        cout << "Set Course as Available?" << endl;
        cout << "1. Yes\n0. No" << endl;
        int input;
        cin >> input;
        if (input == 1 || input == 0)
        {
            newIsAvailable = (input == 1);
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 1 for Yes or 0 for No." << endl;
        }
    }

    // Update course details
    Course* updatedCourse = new Course(newName, newCode, newIsAvailable);

   

    delete courseColl[responseIndex];
    courseColl[responseIndex] = updatedCourse;

    // Update file
    ofstream writer("CourseData.txt");
    for (size_t i = 0; i < courseCount; ++i)
    {
        writer << courseColl[i]->courseCode << ","
            << courseColl[i]->courseName << ","
            << courseColl[i]->isAvailable << ","
            << courseColl[i]->studentCount << ","
            << courseColl[i]->teacherCount << endl;
    }
    writer.close();
}


int CourseCollection::handleCourseSearch(string code)
{
    bool courseFound = false;
    int courseFoundIndex = -1;

    for (int i = 0; i < courseCount; i++)
    {
        if (courseColl[i] != nullptr && code == courseColl[i]->courseCode)
        {
            courseFound = true;
            courseFoundIndex = i;
            break;
        }
    }

    if (!courseFound)
    {
        return -1; // Return -1 if course not matched for conditional matching
    }
    else
    {
        return courseFoundIndex;
    }
}


void CourseCollection::handleDeleteCourse()
{
    cin.ignore();
    string code;
    cout << "Enter course Code: ";
    getline(cin, code);

    int responseIndex = handleCourseSearch(code);
    if (responseIndex == -1)
    {
        cout << "Course Not Found" << endl;
        return;
    }

    // Delete course from collection
    delete courseColl[responseIndex];
    courseCount--;

    // Update file
    ofstream writer("CourseData.txt");
    for (size_t i = 0; i < courseCount ; ++i)
    {
        writer << courseColl[i]->courseCode << ","
            << courseColl[i]->courseName << ","
            << courseColl[i]->isAvailable << ","
            << courseColl[i]->studentCount << ","
            << courseColl[i]->teacherCount << endl;
    }
    writer.close();

}

void  CourseCollection::getCourse(int index)
{
    const int courseCodeWidth = 20; // Width for course code
    const int courseNameWidth = 40; // Wider column for course name
    const int otherColWidth = 20; // Width for other columns

    // Table Header
    cout << left << setw(courseCodeWidth) << "Course Code"
        << setw(courseNameWidth) << "Course Name"
        << setw(otherColWidth) << "Available"
        << setw(otherColWidth) << "Students Enrolled"
        << setw(otherColWidth) << "Teachers Available" << endl;

    // Separator line
    cout << left << setw(courseCodeWidth) << "--------------------"
        << setw(courseNameWidth) << "----------------------------------------"
        << setw(otherColWidth) << "--------------------"
        << setw(otherColWidth) << "--------------------"
        << setw(otherColWidth) << "--------------------" << endl;

    // Table Row
    cout << setw(courseCodeWidth) << courseColl[index]->courseCode
        << setw(courseNameWidth) << courseColl[index]->courseName
        << setw(otherColWidth) << (courseColl[index]->isAvailable ? "Yes" : "No");

    if (courseColl[index]->isAvailable)
    {
        cout << setw(otherColWidth) << courseColl[index]->studentCount;
    }
    else
    {
        cout << setw(otherColWidth) << "--";
    }
    cout << setw(otherColWidth) << courseColl[index]->teacherCount << endl;

    cout << endl;
}

void CourseCollection::handleAddNewCourse()
{
    
    cin.ignore();
    bool setActive;

    cout << "Enter course name:" << endl;
    string tempName;
    getline(cin, tempName);

    cout << "Enter course code:" << endl;
    string tempCode;
    getline(cin, tempCode);

    while (true)
    {
        cout << "Set Course as an Available Course?" << endl;
        cout << "1. Yes\n0. No" << endl;
        int input;
        cin >> input;
        if (input == 1 || input == 0)
        {
            setActive = (input == 1);
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 1 for Yes or 0 for No." << endl;
        }
    }

    courseColl[courseCount] = new Course(tempCode, tempName,setActive);
    
    courseColl[courseCount]->writeCourseData();

    courseCount++;
}

void CourseCollection::loadCourseData()
{
    ifstream reader("CourseData.txt");

    if (!reader.is_open())
    {
        cout << "Error opening course data file." << endl;
        return;
    }

    courseCount = 0; // Reset courseCount before loading

    string line;
    while (getline(reader, line))
    {
        courseColl[courseCount] = new Course();
        courseColl[courseCount]->splitCardData(line);
        courseCount++;
    }

    reader.close(); // Close file after reading
}

void CourseCollection::handleShowAllCourses()
{
    if (courseCount == 0)
    {
        cout << "No courses to show." << endl;
        return;
    }

    cout << "Total Courses: " << courseCount << endl;

    const int courseNameWidth = 40; // Wider column for course name
    const int courseCodeWidth = 30; // Adjusted width for course code
    const int otherColWidth = 20; // Width for other columns

    // Table Header
    cout << left << setw(courseNameWidth) << "Course Name"
        << setw(courseCodeWidth) << "Course Code"
        << setw(otherColWidth) << "Teachers Teaching"
        << setw(otherColWidth) << "Students Enrolled"
        << setw(otherColWidth) << "Available?" << endl;

    // Separator line
    cout << left << setw(courseNameWidth) << "----------------------------------------"
        << setw(courseCodeWidth) << "------------------------------"
        << setw(otherColWidth) << "--------------------"
        << setw(otherColWidth) << "--------------------"
        << setw(otherColWidth) << "--------------------" << endl;

    // Table Rows
    for (int i = 0; i < courseCount; i++) {
        cout << setw(courseNameWidth) << courseColl[i]->courseName
            << setw(courseCodeWidth) << courseColl[i]->courseCode
            << setw(otherColWidth) << courseColl[i]->teacherCount;

        if (courseColl[i]->isAvailable)
        {
            cout << setw(otherColWidth) << courseColl[i]->studentCount;
        }
        else 
        {
            cout << setw(otherColWidth) << "--";
        }
        cout << setw(otherColWidth) << (courseColl[i]->isAvailable ? "Yes" : "No") << endl;
    }
    cout << endl;
}
