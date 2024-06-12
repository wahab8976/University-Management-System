#include "University.h"
#include "Utils.h"
#include "Admin.h"

	University::University()
	{
		currentPerson.loadPersonData();
	}

	void University ::runSetup()
	{
		bool personFound = false;
		int personFoundIndex = -1;
		cout << "WellCome..." << endl;
		cout << "Enter your ID" << endl;
		long long tempId = Utility::getNumericInput(4);

		for (int i = 0; i < currentPerson.personCount; i++)
		{
			if (tempId == currentPerson.PersonColl[i]->id)
			{
				personFound = true;
				personFoundIndex = i;
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
			while (true)	// Iterate if the password provided is empty
			{
				getline(cin, tempPass);		
				if (tempPass.empty())
				{
					cout << "Please Provide a password: ";
				}
				else
				{
					break;
				}
			}
			
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

		switch (loggedInUser->personType)
		{
		case ADMIN:
		{
			Admin* adminUser = static_cast<Admin*>(loggedInUser);
			adminUser->showMenuMenu();
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

