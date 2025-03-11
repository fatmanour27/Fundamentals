#include "ArrayList.h"


using namespace std;

int main()
{
    ArrayList<int> l; // Creating an ArrayList of integers
    for (int i = 0; i < 5; i++)
    {
        l.append(i);
    }

    int choice, value, index;

    while (true)
    {
        cout << "Choose an operation:" << endl
            << "1: Append item in ArrayList" << endl
            << "2: Insert at Index" << endl
            << "3: Display items" << endl
            << "4: Reverse and Display" << endl
            << "5: Search specific item" << endl
            << "6: Delete by Index" << endl
            << "7: Access & Modify Element" << endl
            << "0: Exit" << endl
            << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter value to add: ";
            cin >> value;
            l.append(value);
            cout << "Value added successfully" << endl;
            break;

        case 2:
            cout << "Enter index to insert at: ";
            cin >> index;
            cout << "Enter value to insert: ";
            cin >> value;
            try
            {
                l.insert(index, value);
                cout << "Value inserted successfully" << endl;
            }
            catch (const exception& e)
            {
                cout << "Exception: " << e.what() << endl;
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
                int length = l.getLength();
                l.reverse(length);
                l.display();
                l.reverse(length);
            }
            catch (const exception& e)
            {
                cout << "Exception: " << e.what() << endl;
            }
            break;

        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            index = l.search(value);
            if (index != -1)
            {
                cout << "Value found at index: " << index << endl;
            }
            else
            {
                cout << "Value not found" << endl;
            }
            break;

        case 6:
            cout << "Enter index to delete: ";
            cin >> index;
            try
            {
                l.Delete(index);
                cout << "Value deleted successfully" << endl;
            }
            catch (const exception& e)
            {
                cout << "Error: " << e.what() << endl;
            }
            break;

        case 7: //using operator[] to access index direct in ArrayList and change its value
            cout << "Enter index to access: ";
            cin >> index;
            if (index > l.getLength() - 1)
            {
                cout << "The index out of range" << endl;
            }
            try
            {
                cout << "Current value is: " << l[index] << endl;
                cout << "its index is: " << index << endl;
                cout << "Enter new value will be modified: ";
                cin >> value;
                l[index] = value;
                cout << "Value updated successfully" << endl;
            }
            catch (const exception& e)
            {
                cout << "Error: " << e.what() << endl;
            }
            break;

        case 0:
            cout << "Exiting program" << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again" << endl;
        }
    }

    return 0;
}


