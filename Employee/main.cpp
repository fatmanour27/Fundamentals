#include "Employee.h"

int main()
{
	try
	{
		Employee emp;
		int choice;
		string id;

		while (true)
		{
			cout << "Enter your choice from employees list: "<<endl
				<< "1: To add data of new employee." << endl
				<< "2: To display data of one employee." << endl
				<< "3: To modify on data of specific employee." << endl
				<< "0: To exit." << endl;
			
			cin >> choice;

			if (cin.fail())
			{
				cout << "Invalid input! Please enter a number between 0-3." << endl;
				cout << "----------------------------------------------------------" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}

			switch (choice)
			{
			case 1:
				emp.addEmployee();
				break;
			case 2:
				cout << "Enter the id of employee you search for:" << endl;
				cin >> id;
				emp.showSpecificEmployee(id);
				break;
			case 3:
				cout << "Enter the id of employee will be deleted:" << endl;
				cin >> id;
				emp.deleteEmployee(id);
				break;
			case 0:
				cout << "You are exited now" << endl;
				return 0;
			default:
				cout << "Invalid input. Please try again!" << endl;
				break;
			}
		}
	}
	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
	
	return 0;
}
