#include "CourseCollection.h"
#include "Utils.h"


CourseCollection::CourseCollection()
{
	courseCount = 0;
}

void CourseCollection::loadCourseData()
{
	ifstream reader("CourseData.txt");

	if (!reader.is_open())
	{
		cout << "Error opening course data" << endl;
		return;
	}	
	else
	{
		string line = "";
		while (getline(reader,line))
		{
			courseColl[courseCount].splitCardData(line);
			courseCount++;
		}
	}


}