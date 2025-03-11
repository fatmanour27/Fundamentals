#include "double_LinkedList.h"


int main()
{
    LinkedList<int> l;

    for (int i = 0; i < 5; i++)
    {
        l.addFirst(i);
    }

    int choice, value, indexValue;

    while (true)
    {
        cout << "Choose any from these operations:" << endl
            << "1: Append" << endl
            << "2: Add Before a Specific Value" << endl
            << "3: Display" << endl
            << "4: Display Reverse" << endl
            << "5: Search" << endl
            << "6: Count" << endl
            << "7: Delete First and Retrieve" << endl
            << "8: Delete Specific and Retrieve" << endl
            << "0: Exit" << endl
            << "Enter your choice: ";
        cin >> choice;
        //new way and perfect instead of make choice is a string and validate it then convert it to integer in switch block
        if (cin.fail())  //if user enter input isn't a number fail function will return true
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  //ignore all characters until a newline (\n) is found
            cout << "Invalid input! Please enter a number" << endl;
            continue;
        }

        switch (choice)
        {
        case 1: 
            cout << "Enter value to append: ";
            cin >> value;
            l.append(value);
            cout << "Value appended successfully" << endl;
            break;

        case 2:
            cout << "Enter the value before which to insert: ";
            cin >> indexValue;
            cout << "Enter new value to insert: ";
            cin >> value;
            try
            {
                l.addSpecific(indexValue, value);
                cout << "Value inserted successfully before this indexValue: " << indexValue <<endl;
            }
            catch (const exception& e)
            {
                cout << "Error: " << e.what() << endl;
            }
            break;

        case 3:
            try
            {
                l.display();
            }
            catch (const exception& e)
            {
                cout << "Exception: " << e.what() << endl;
            }
            break;

        case 4:
            try
            {
                l.displayReverse();
            }
            catch (const exception& e)
            {
                cout << "Exception: " << e.what() << endl;
            }
            break;

        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            if (l.search(value))
            {
                cout << "The value you search for is: " << value <<endl;
            }
            else
            {
                cout << "Value not found" << endl;
            }
            break;

        case 6:
            try
            {
                cout << "Number of elements: " << l.count() << endl;
            }
            catch (const exception& e)
            {
                cout << "Exception: " << e.what() << endl;
            }
            break;

        case 7:
            try
            {
                cout << "The deleted first value is: " << l.deleteFirstAndRetrieve() << endl;
            }
            catch (const exception& e)
            {
                cout << "Exception: " << e.what() << endl;
            }
            break;

        case 8:
            cout << "Enter value to delete: ";
            cin >> value;
            try
            {
                cout << "The deleted value is: " << l.deleteSpecificAndRetrieve(value) << endl;
            }
            catch (const exception& e)
            {
                cout << "Exception: " << e.what() << endl;
            }
            break;

        case 0:
            cout << "Exiting program" << endl;
            return 0;

        default:
            cout << "Invalid choice! try agin" << endl;
        }
    }
    return 0;
}

