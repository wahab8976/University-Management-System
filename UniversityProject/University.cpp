#include "University.h"

	University::University()
	{
		currentPerson.loadPersonData();
	}

	void University ::runSetup()
	{
		long tempId = 0;
		bool personFound = false;
		int personFoundIndex = -1;
		cout << "WellCome..." << endl;
		cout << "Enter Your ID" << endl;
		cin >> tempId;

		for (int i = 0; i < currentPerson.personCount; i++)
		{
			if (tempId == currentPerson.PersonColl[i]->id)
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
			getline(cin, tempPass);

			if (tempPass == currentPerson.PersonColl[personFoundIndex]->password)
			{
				cout << "User Authenticated" << endl;

			}
			else
			{
				cout << "Password does not match!" << endl;
				return;
			}
		}

		Person* loggedInUser = currentPerson.PersonColl[personFoundIndex]; // Person Pointer to hold current User who logged in

		for (int i = 0; i < currentPerson.personCount; i++)
		{
			if (currentPerson.PersonColl[i] == loggedInUser)
			{
				continue;
			}
			delete currentPerson.PersonColl[i];
		}

		switch (currentPerson.PersonColl[personFoundIndex]->personType)
		{
		case ADMIN:
		{
			cout << "Admin" << endl;
			break;
		}
		break;
		case TEACHER:
			cout << "Teacher" << endl;
			break;
		case STUDENT:
			cout << "Student" << endl;
			break;
		default:
			cout << "Invalid User Type" << endl;
			break;
		}
	}

