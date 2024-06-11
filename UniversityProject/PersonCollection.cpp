#include "PersonCollection.h"




	PersonCollection::PersonCollection()
	{
		personCount = 0;
	}

	void PersonCollection::loadPersonData()
	{
		ifstream reader("personData.txt");
		string line = "";

		if (!reader.is_open())
		{
			cout << "Cannot Open File" << endl;
			return;
		}
		else
		{
			while (getline(reader, line))
			{
				PersonColl[personCount] = new  Person();
				PersonColl[personCount]->splitPersonData(line);
				personCount++;
			}
			cout << "PersonCount: " << personCount << endl;
		}



	}

