#include "single_LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> l;

    for (int i = 0; i < 5; i++)
    {
        l.add(i);
    }

    int choice, value, indexValue;

    while (true)
    {
        cout << "Choose any from these operations:" << endl
            << "1: Append" << endl
            << "2: Add Before a Specific Value" << endl
            << "3: Display" << endl
            << "4: Count Elements" << endl
            << "5: Search" << endl
            << "6: Delete First and Retrieve" << endl
            << "7: Delete Specific and Retrieve" << endl
            << "0: Exit" << endl
            << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())  //perfect way
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number" << endl;
            continue;
        }
        switch (choice)
        {
        case 1:
            cout << "Enter value to append: ";
            cin >> value;
            l.append(value);
            cout << "Value appended successfully." << endl;
            break;

        case 2:
            cout << "Enter the value before which to insert: ";
            cin >> indexValue;
            cout << "Enter new value to insert: ";
            cin >> value;
            try
            {
                l.addBefore(indexValue, value);
                cout << "Value inserted successfully before " << indexValue << endl;
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
                cout << "Number of elements: " << l.count() << endl;
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
                cout << "The value " << value << " is found in the list." << endl;
            }
            else
            {
                cout << "Value not found." << endl;
            }
            break;

        case 6:
            try
            {
                l.deleteFirst();
                cout << "First element deleted successfully." << endl;
            }
            catch (const exception& e)
            {
                cout << "Exception: " << e.what() << endl;
            }
            break;

        case 7:
            cout << "Enter value to delete: ";
            cin >> value;
            try
            {
                l.deleteSpecific(value);
                cout << "Value " << value << " deleted successfully." << endl;
            }
            catch (const exception& e)
            {
                cout << "Exception: " << e.what() << endl;
            }
            break;

        case 0:
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please enter a valid option (0-7).\n";
        }
    }

    return 0;
}
