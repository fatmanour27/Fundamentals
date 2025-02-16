#include "BigInt.cpp"
#include <iostream>

using namespace std;

int main()
{
    try
    {
        string num1, num2, sign;
        BigInt validator("0");

        while (true)
        {
            cout << "Enter the first string: ";
            cin >> num1;

            // Validate first number
            if (!validator.GetValid(num1))
            {
                cout << "Invalid input! Please enter a valid number"<<endl;
                continue;
            }

            cout << "Enter the Arithmetic operator (+, -, *, /, %, ^): ";
            cin >> sign;

            cout << "Enter the second string: ";
            cin >> num2;

            // Validate second number
            if (!validator.GetValid(num2))
            {
                cout << "Invalid input! Please enter a valid number"<<endl;
                continue;
            }

            BigInt a = num1, b = num2;
            BigInt result;

            if (sign == "+")
                result = a + b;
            else if (sign == "-")
                result = a - b;
            else if (sign == "*")
                result = a * b;
            else if (sign == "/")
            {
                if (b == BigInt("0"))
                {
                    cout << "Division by zero is not allowed"<<endl;
                    continue;
                }
                result = a / b;
            }
            else if (sign == "%")
            {
                if (b == BigInt("0"))
                {
                    cout << "Modulo by zero is not allowed" << endl;
                    continue;
                }
                result = a % b;
            }
            else if (sign == "^")
            {
                if (b < BigInt("0"))
                {
                    cout << "Negative exponent not supported"<<endl;
                    continue;
                }
                result = a ^ b;
            }
            else
            {
                cout << "Invalid operator! Please enter a valid operator (+, -, *, /, %, ^): "<<endl;
                continue;
            }

            cout << "Result: " << result << endl;
            cout << "Enter -1 to exit or any other number to continue: ";
            string exitCheck;
            cin >> exitCheck;
            if (exitCheck == "-1")  // Exit condition after calculation
                break;
        }
    }
    catch (const exception& e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
