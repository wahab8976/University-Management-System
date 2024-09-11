#include "StudentCollection.h"


StudentCollection::StudentCollection()
{
	studentCount = 0;
}

void StudentCollection::loadStudentsData()
{
	ofstream writer("StudentsData.txt");
	for (int i = 0; i < studentCount; i++)
	{

	}
	writer.close();
}