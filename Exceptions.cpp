#include <iostream>
#include <exception>
#include <climits>
#include <string>
#include <cmath>
using namespace std;

//bad_alloc derived class from base class exception
void BadAllocation()
{
	try
	{
		int size;
		cout << "Enter the size of array: " << endl;
		cin >> size;
		int* arr = new int[size];

		if (size >= 1000)
		{
			delete[]arr;       //Free the allocated memory to avoid memory leaks before throwing an exception
			throw bad_alloc();

		}
		else if (size <= 0)  //when the user input size < 0 the specific message"Invalid Array size" will not thrown and the derived class 'runtime_error' will throw its default message in this case
		{
			throw runtime_error("Invalid Array size");
		}
		else
		{
			cout <<"Array of size "<< size << " allocated successfully"<<endl;
		}
	}
	catch (const bad_alloc& b)
	{
		cout << "Memory allocation error:"<<b.what() << endl;
	}
	catch (const runtime_error& t)
	{
		cout << t.what() << endl;
	}
	
}
void ArgError(int PositiveValue)
{
	try
	{
		cout << "Enter a positive number: ";
		cin >> PositiveValue;

		if (PositiveValue < 0)
		{
			throw invalid_argument("Exception with a negative argument");
		}
		else
		{
			cout << "Value is valid: " << PositiveValue << endl;
		}
	}
	catch(const invalid_argument& inv)
	{
		cout << inv.what() << endl;
	}
}
void DomainError()
{
	try
	{
		int num;
		cout << "Enter positive number greater than zero: ";
		cin >> num;

		if (num <= 0)
		{
			throw domain_error("Exception: the number should be greater than zero");
		}
		else
		{
			int factorial = 1;
			for (int counter = 1; counter <= num; counter++) 
			{
				factorial *= counter;
			}
			cout << "factorial is: " << factorial << endl;
		}
	}
	catch (const domain_error& d)
	{
		cout << d.what() << endl;
	}
}
void DivideByZero()
{
	try
	{
		int denominator, numerator;
		cout << "Enter numerator and denominator positive number non-zero: "<<endl;
		cin >> numerator >> denominator;

		if (denominator == 0)
		{
			throw domain_error("Can't divided by zero");
		}
		else
		{
			cout << "The result of division: " << numerator / denominator << endl;
			cout << "The denominator a positive non-zero number is: " << denominator << endl;
		}
	}
	catch (const domain_error& d)
	{
		cout << "Exception: " << d.what() << endl;
	}
}
//runtime_error derived class from exception and base class for 3 derived classes
//overflow_error derived class from runtime_error
void RangeError()
{
	try
	{
		int arr[] = { 1, 3, 7, 9, 10 };
		int index;
		cout << "Enter the index of array value:" << endl;
		cin >> index;

		if (index < 0)
		{
			throw range_error("Negative index not valid");
		}
		else
		{
			cout << "The value of index " << index << " is: " << arr[index] << endl;
		}
	}
	catch (const range_error& r)
	{
		cout << "Exception: " << r.what() << endl;
	}
}
void UnderFlow() 
{
	try
	{
		float value;
		cout << "Enter float value: ";
		cin >> value;

		if (value < FLT_MIN && value != 0.0 )    //A negative value "alone" is not necessarily an underflow but a negative floating value considered as very small floating point
		{
			throw underflow_error("The value of floating point is very small");
		}
		else
		{
			cout << "The value is valid = " << value << endl;
		}
	}
	catch (const underflow_error& unf)
	{
		cout << "Exception: " << unf.what() << endl;
	}
}
void EnterInteger()
{
	try
	{
		string input;
		cout << "Enter an integer number: " << endl;
		cin >> input;

		char Character;
		for (int i = 0; i < input.length(); i++)
		{
			Character = input[i];
		}
		if (!isdigit(Character))
		{
			throw("Invalid input you should enter an integer");
		}
		else
		{
			int IntValue = stoi(input);
			cout << "The integer value is: " << IntValue << endl;
		}
	}
	catch (const char* e)
	{
		cout << "Caught Exception: " << e << endl;
	}
}
void SquareRoot()
{
	try
	{
		int value;
		cout << "Enter the value:" << endl;
		cin >> value;

		if (value <= 0)
		{
			throw("Invalid square root for negative or zero value");
		}
		else
		{
			cout << "Square root of " << value << " is: " << sqrt(value) << endl;
		}
	}
	catch (const char* sq)
	{
		cout << "Exception: " << sq << endl;
	}
}
void Temperature()
{
	try
	{
		float Celsius = -273.15;
		int Temperature;
		cout << "Enter the temperature in Celsius: " << endl;
		cin >> Temperature;

		if (Temperature < Celsius)
		{
			throw("The temperature less than absolute zero -273 Celsius");
		}
		else if (Temperature > 0)
		{
			throw overflow_error("The temperature in Celsius invalid");
		}
		else
		{
			cout << "The temperature in Celsius: " << Temperature << endl;
		}

	}
	catch (const char* temp)
	{
		cout << "Exception: " << temp << endl;
	}
	catch (const overflow_error& ov)
	{
		cout << "Exception: " << ov.what() << endl;
	}
}
int main()
{
	BadAllocation();
	ArgError(-1);
	DomainError();
	DivideByZero();
	RangeError();
	UnderFlow();
	EnterInteger();
	SquareRoot();
	Temperature();

	return 0;
}