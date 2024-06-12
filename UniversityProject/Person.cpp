#include "Person.h"




	Person::Person()
	{
		email = address = "Annonymous";
	}

	void Person:: splitPersonData(string  line)
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

		pos = line.find(",");
		token = line.substr(0, pos);
		CNIC = stoll(token);
		line.erase(0, pos + 1);

		phone = stoll(line);


	}
