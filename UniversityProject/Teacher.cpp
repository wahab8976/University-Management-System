#include "Teacher.h"
#include  "Utils.h"

Teacher::Teacher()
{
	cout << "Teacher is Created!" << endl;
}

void Teacher::writeTeacherData()
{
	Teacher teacher[10];
    /*
    
    teacher[0].name = "Umar Ali";
    teacher[0].address = "District Gujrat";
    teacher[0].attendPercent = 88;
    teacher[0].CNIC = 23139893024;
    teacher[0].courseTeaching = AI;
    teacher[0].email = "umar@example.com";
    teacher[0].gndr = MALE;
    teacher[0].id = 2222;
    teacher[0].isPaid = false;
    teacher[0].password = "umar123";
    teacher[0].phone = 323234244;
    teacher[0].presentToday = true;
    teacher[0].salary = 100000;
    teacher[0].title = PROFESSOR;

    teacher[1].name = "Aisha Khan";
    teacher[1].address = "Islamabad";
    teacher[1].attendPercent = 95;
    teacher[1].CNIC = 321456789;
    teacher[1].courseTeaching = webTech;
    teacher[1].email = "aisha@example.com";
    teacher[1].gndr = FEMALE;
    teacher[1].id = 3333;
    teacher[1].isPaid = true;
    teacher[1].password = "aisha456";
    teacher[1].phone = 345678123;
    teacher[1].presentToday = true;
    teacher[1].salary = 90000;
    teacher[1].title = LECTURER ;

    // Teacher 3
    teacher[2].name = "Ahmed Hassan";
    teacher[2].address = "Lahore";
    teacher[2].attendPercent = 92;
    teacher[2].CNIC = 987654321;
    teacher[2].courseTeaching = ML;
    teacher[2].email = "ahmed@example.com";
    teacher[2].gndr = MALE;
    teacher[2].id = 4444;
    teacher[2].isPaid = true;
    teacher[2].password = "ahmed789";
    teacher[2].phone = 321987654;
    teacher[2].presentToday = false;
    teacher[2].salary = 85000;
    teacher[2].title = PROFESSOR;

    // Teacher 4
    teacher[3].name = "Sara Malik";
    teacher[3].address = "Karachi";
    teacher[3].attendPercent = 85;
    teacher[3].CNIC = 135792468;
    teacher[3].courseTeaching = AI;
    teacher[3].email = "sara@example.com";
    teacher[3].gndr = FEMALE;
    teacher[3].id = 5555;
    teacher[3].isPaid = true;
    teacher[3].password = "sara321";
    teacher[3].phone = 332211445;
    teacher[3].presentToday = true;
    teacher[3].salary = 95000;
    teacher[3].title = LECTURER;
    
    */
	



	ofstream writer("TeacherData.txt");

	

	writer.close();
}