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

void CourseCollection::handleAddNewCourse()
{
    
    cin.ignore();

    cout << "Enter course name:" << endl;
    string tempName;
    getline(cin, tempName);

    cout << "Enter course code:" << endl;
    string tempCode;
    getline(cin, tempCode);

    courseColl[courseCount] = new Course();
    courseColl[courseCount]->setCourseName(tempName);
    courseColl[courseCount]->setCourseCode(tempCode);
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
        << setw(otherColWidth) << "Teachers Available"
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
