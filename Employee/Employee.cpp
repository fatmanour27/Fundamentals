#include "Employee.h"


bool Employee::validateId(string id)
{
	if (!isalpha(id[0]))
	{
		cout << ("ID must start with an alphabetic character.") << endl;
		return false;
	}
	for (int i = 1; i < id.length(); i++)
	{
		while (!isdigit(id[i]))
		{
			cout << ("ID must have an alphabetic character followed by digits only.") << endl;
			return false;
		}
	}
	return true;
}
bool Employee::validateAlphabetic(string n)
{
	for (char c : n)
	{
		if (!isalpha(c))
		{
			cout << ("Name or status or achievements must contain only alphabetic characters.") << endl;
			return false;
		}
	}
	return true;
}
bool Employee::validateSalaryAndBonus(string salAndBonus) //we pass the salary as a string to check if the user enter non-numeric characters.
{
	for (int i = 0; i < salAndBonus.length() - 1; i++)
	{
		if (!isdigit(salAndBonus[i]))
		{
			cout << ("Salary or Bonus must be digits exculded the last digit") << endl;
			return false;
		}
		if ((salAndBonus.back()) != '$') //if last character in string is digit
		{
			cout << ("The last character must be $ not digit") << endl;
			return false;
		}
	}
	if (stoi(salAndBonus) <= 0)
	{
		cout << ("The negative numbers or zero not allowed.") << endl;
		return false;
	}
	return true;
}
void Employee::variableLength(string titles[], string attributes[], int maxLength[], int size)
{
	for (int i = 0; i < size; i++)  //compare the length of title with data will be entered and take the max length
	{
		maxLength[i] = max(titles[i].length(), attributes[i].length());
	}
}
bool Employee::isExist(string fname, string id) //check if the id has been entered is aleardy exist or not.
{
	fstream file(fname);
	string line;
	while (getline(file, line))
	{
		stringstream ss(line);
		string firstWordId;
		ss >> firstWordId;  //extract the first word in each line

		if (firstWordId == id)
		{
			return true;
		}
	}
	return false;
}
bool Employee::isEmpty(string fname) 
{
	fstream file(fname);
	string line;
	if (getline(file, line)) //if there are lines in file. the file isn't empty
	{
		return false;
	}
	return true;
}
void Employee::addEmployee()
{
	string id, name, salary, bonus, email, status, workModel;
	string achievement, task, role, behavior, responsibility, skills;

	int const SIZE = 14;
	int maxLength[SIZE];

	string titles[SIZE] = { "ID", "Name", "Salary", "Bonus","Email", "Status", "Work Model",
						    "Achievement", "Project", "Role","Behavior", "Responsibility", "Skills" };

	while (true)
	{

		cout << ("Enter The id of the name to be added:") << endl;
		cin >> id;
		while (!validateId(id))
		{
			cout << ("Please try again to enter the id:") << endl;
			cin >> id;
		}
		if (isExist("Data.txt", id))
		{
			cout << ("The employee already exist in file. please try again") << endl;
			continue;
		}
		else
		{
			cout << ("You can add this employee:") << endl;
		}
		
		cout << ("Enter the name of employee will be added:") << endl;
		cin >> name;
		while (!validateAlphabetic(name))
		{
			cout << ("Please try again to enter the name or status:") << endl;
			cin >> name;
		}
		cout << ("Enter the salary of employee to be added:") << endl;
		cin >> salary;
		while (!validateSalaryAndBonus(salary))
		{
			cout << ("Please try again to enter the salary or bonus:") << endl;
			cin >> salary;
		}
		cout << ("Enter the bonus of employee to be added:") << endl;
		cin >> bonus;
		while (!validateSalaryAndBonus(bonus))
		{
			cout << ("Please try again to enter the salary or bonus:") << endl;
			cin >> bonus;
		}
		cout << ("Enter the email of employee to be added:") << endl;
		cin >> email;
		
		cout << ("Enter the status of employee to be added:") << endl;
		cin >> status;
		while (!validateAlphabetic(status))
		{
			cout << ("Please try again to enter name or status:") << endl;
			cin >> status;
		}

		cout << ("Enter the work model of employee (remote-hybrid-onsite)") << endl;
		cin >> workModel;

		cout << ("Enter the achievements of employee:") << endl;
		cin >> achievement;
		while (!validateAlphabetic(achievement))
		{
			cout << ("Please try again to enter the achievement:") << endl;
			cin >> achievement;
		}

		cout << ("Enter the name of current projects of employee:") << endl;
		cin >> task;
		while (!validateAlphabetic(task))
		{
			cout << ("Please try again to enter the name of current project:") << endl;
			cin >> task;
		}

		cout << ("Enter the name of the role of employee:") << endl;
		cin >> role;
		while (!validateAlphabetic(role))
		{
			cout << ("Please try again to enter the role:") << endl;
			cin >> role;
		}

		cout << ("Enter the behavior of employee:") << endl;
		cin >> behavior;
		while (!validateAlphabetic(behavior))
		{
			cout << ("Please try again to enter the behavior:") << endl;
			cin >> behavior;
		}

		cout << ("Enter the responsibility of employee:") << endl;
		cin >> responsibility;
		while (!validateAlphabetic(responsibility))
		{
			cout << ("Please try again to enter the responsibility:") << endl;
			cin >> responsibility;
		}

		cout << ("Enter the skills of employee:") << endl;
		cin >> skills;
		while (!validateAlphabetic(skills))
		{
			cout << ("Please try again to enter the skills:") << endl;
			cin >> skills;
		}
		break;
	}
	string attributes[SIZE] = {id, name, salary, bonus, email, status, workModel,
								achievement, task, role, behavior, responsibility, skills};

	variableLength(titles, attributes, maxLength, SIZE);

	file.open("Data.txt", ios::app);
	if (!file.is_open())
	{
		throw runtime_error("The file isn't opened");
	}
	
	if (isEmpty("Data.txt"))
	{
		for (int i = 0; i < SIZE; i++)
		{
			file << left << setw(maxLength[i] + 2) << titles[i];
		}
		file << endl;
	}

	for (int i = 0; i < SIZE; i++)
	{
		file << left << setw(maxLength[i] + 2) << attributes[i];
	}
	file << endl;

	cout << ("The file of employee saved successfully") << endl;
	file.close();
}
void Employee::showSpecificEmployee(string id)
{
	file.open("Data.txt", ios::in);
	if (!file.is_open())
	{
		throw runtime_error("The file isn't opened");
	}
	if (isEmpty("Data.txt"))
	{
		cout << ("file is empty! you can't display any data") << endl;
		file.close();
		return;
	}
	string line;
	bool isfound = false;
	while (getline(file, line))
	{
		stringstream ss(line);
		string firstWord;
		ss >> firstWord;
		if (firstWord == id)
		{	
			cout << ("The data of employee you searched for is: ") << line << endl;
			isfound = true;
			break;
		}
	}
	file.close();
	if (!isfound)
	{
		cout << ("The employee not found. please try again") << endl;
		cin >> id;
	}
}
void Employee::deleteEmployee(string id)
{
	file.open("Data.txt", ios::in);  //will copy its content in another file after deleting

	if (!file.is_open())
	{
		throw runtime_error("The file isn't opened");
	}
	if (isEmpty("Data.txt"))
	{
		cout << ("file is empty! you can't edit any data") << endl;
		file.close();
		return;
	}

	fstream temp;
	temp.open("Temp.txt", ios::out);
	string line;
	bool isfound = false;

	while (getline(file, line))
	{
		stringstream ss(line);
		string firstWord;
		ss >> firstWord;

		if (firstWord == id)
		{
			isfound = true;
			continue;  //ignore this line that will be deleted
		}
		temp << line << endl;
	}
	file.close();
	temp.close();

	if (isfound)  //if the line we will be deleted not found move the data from original file to temp file and rename it and delete the original file
	{
		remove("Data.txt");
		rename("Temp.txt", "Data.txt");
	}
	else
	{
		remove("Temp.txt");
	}	
}

