
#include <iostream>
#include<string>
#include<fstream>
using namespace std;

enum Role
{
	ADMIN = 1,
	TEACHER,
	STUDENT
};

class Person
{
public:
	string name, password;
	long long id, CNIC;
	Role personType;

	Person()
	{
		cout << "PErson..." << endl;
	}

	void splitPersonData(string  line)
	{
		size_t pos = 0;
		string token = "";

		pos = line.find(",");
		token = line.substr(0, pos);
		personType = static_cast<Role>(stoi(token));
		line.erase(0, pos + 1);

		pos = line.find(",");
		token = line.substr(0, pos);
		id = stoll(token);
		line.erase(0, pos + 1);

		pos = line.find(",");
		token = line.substr(0, pos);
		name = token;
		line.erase(0, pos + 1);

		pos = line.find(",");
		token = line.substr(0, pos);
		password = token;
		line.erase(0, pos + 1);

		CNIC = stoll(line);
	}
};

class PersonCollection
{
public:
	Person PersonColl[100];
	int personCount;

	PersonCollection()
	{
		personCount = 0;
	}

	void loadPersonData()
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
				PersonColl[personCount].splitPersonData(line);
				personCount++;
			}
			cout << "PersonCount: " << personCount << endl;
		}



	}



};

class University
{
public:
	PersonCollection currentPerson;
	University()
	{
		currentPerson.loadPersonData();
	}

	void runSetup()
	{
		long tempId = 0;
		bool personFound = false;
		int personFoundIndex = -1;

		cout << "Enter Your ID" << endl;
		cin >> tempId;

		for (int i = 0; i < currentPerson.personCount; i++)
		{
			if (tempId == currentPerson.PersonColl[i].id)
			{
				personFound = true;
				personFoundIndex = i;
				cout << "at index " << i << endl;
				break;
			}
		}

		if (!personFound)
		{
			cout << "User Not Found" << endl;
			return;
		}
		else
		{
			string tempPass = "";
			cout << "Enter your Password: ";
			cin.ignore();
			getline(cin,tempPass);

			if (tempPass == currentPerson.PersonColl[personFoundIndex].password)
			{
				cout << "User Authenticated" << endl;

			}
			else
			{
				cout << "Password does not match!" << endl;
				return;
			}
		}

		Person* loggedInUser = &currentPerson.PersonColl[personFoundIndex]; // Person Pointer to hold current User who logged in

		switch (currentPerson.PersonColl[personFoundIndex].personType)
		{
		case ADMIN:
		{
			cout << "teacher" << endl;
			break;
		}
			
			break;
		case TEACHER:
			cout << "teacher" << endl;
			break;
		case STUDENT:
			cout << "Student" << endl;
			break;
		default:
			cout << "Invalid User Type" << endl;
			break;
		}
	}

};

int main()
{
	University u1;
	u1.runSetup();
}

