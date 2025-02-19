#include <iostream>
#include <string>
using namespace std;

void Rhombus()
{
	int h;
	cout << "Enter the height of Rhombus: ";
	cin >> h;

	int spaces = h - 1;
	int stars = 1;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < spaces; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < stars; j++)
		{
			cout << "*";
		}
		cout << endl;
		spaces -= 1;
		stars += 2;
	}
	for (int i = h; i >= 0; i--)
	{
		for (int j = spaces; j >= 0; j--)
		{
			cout << " ";
		}
		for (int j = stars - 3; j >= 0; j--)
		{
			cout << "*";
		}
		cout << endl;
		stars -= 2;
		spaces += 1;
	}
}
void HollowRhombus()
{
	int h;
	cout << "Enter the height of hollow Rhombus: ";
	cin >> h;

	int spaces = h - 1;
	int stars = 1;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < spaces; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < stars; j++)
		{
			if (i == 0 || i == h || j == 0 || j == stars - 1)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
		spaces -= 1;
		stars += 2;

	}
	for (int i = h; i >= 0; i--)
	{
		for (int j = spaces; j > 0; j--)
		{
			cout << " ";
		}
		for (int j = stars - 3; j >= 0; j--)
		{
			if (i < h && j == stars - 3)
			{
				cout << " ";
			}
			if (i == 1 || j == stars - 3 || j == 0)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
		spaces += 1;
		stars -= 2;
	}
}
void Rectangle()
{
	//we draw the rectangle using concept of Pyramid
	int h;
	cout << "Enter the height of Rectangle: ";
	cin >> h;

	int spaces = h - 1;
	int stars = 1;

	for (int i = 0; i < h; i++)
	{
		//left side: inverted right triangle
		for (int j = 0; j < spaces; j++)
		{
			cout << "*";
		}
		//pyramid
		for (int j = 0; j < stars; j++)
		{
			cout << "*";
		}
		//right side: inverted right triangle
		for (int j = 0; j < spaces; j++)
		{
			cout << "*";
		}
		cout << endl;
		spaces -= 1;
		stars += 2;
	}
}
void HollowRectangle()
{
	int h, w;
	cout << "Enter the height of hollow Rectangle: ";
	cin >> h;
	cout << "Enter the width of Hollow Rectangle: ";
	cin >> w;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	
}
void Butterfly()
{
	int h;
	cout << "Enter the height of Butterfly: ";
	cin >> h;

	int spaces = h - 1;
	int stars = 1;
	//top two right triangle
	for (int i = 0; i < h ; i++)
	{
		for (int j = 0; j < stars; j++)
		{
			if (i == h - 1 && j != stars - 1)
			{
				cout << " ";
			}
			else
			{
				cout << "*";
			}
		}
		for (int j = 0; j < 4 * (spaces - i); j++)
		{
			cout << " ";
		}
		for (int j = 0; j < stars; j++)
		{
			if (i == h - 1 && j != 0)
			{
				cout << " ";
			}
			else
			{
				cout << "*";
			}
		}
		cout << endl;
		stars += 2;
	}
	//bottom two right triangle
	for (int i = h - 1; i >= 0; i--)
	{
		for (int j = stars - 3; j >= 0; j--)
		{
			if (i == h - 1 && j != 0)
			{
				cout << " ";
			}
			else
			{
				cout << "*";
			}
		}
		for (int j = 0; j < 4 * (spaces - i); j++)
		{
			cout << " ";
		}
		for (int j = stars - 3; j >= 0; j--)
		{
			if (i == h - 1 && j != stars - 3)
			{
				cout << " ";
			}
			else
			{
				cout << "*";
			}
		}
		cout << endl;
		stars -= 2;
	}
}
void HollowButterfly()
{
	int h;
	cout << "Enter the height of hollow Butterfly: ";
	cin >> h;

	int spaces = h - 1;
	int stars = 1;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < stars; j++)
		{
			if (i == 0 || j == 0 || j == stars - 1)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		for (int j = 0; j < 4 * (spaces - i); j++)
		{
			cout << " ";
		}
		for (int j = 0; j < stars; j++)
		{
			if (i == 0 || j == 0 || j == stars - 1)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
		stars += 2;
	}
	for (int i = h - 1; i >= 0; i--)
	{
		for (int j = stars - 3; j >= 0; j--)
		{
			if (i == 0 || j == 0 || j == stars - 3)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		for (int j = 0; j < 4 * (spaces - i); j++)
		{
			cout << " ";
		}
		for (int j = stars - 3; j >= 0; j--)
		{
			if (i == 0 || j == 0 || j == stars - 3)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
		stars -= 2;
	}
}

int main()
{
	string choice;

	while (true)
	{
		cout << "Choose your better shape: " << endl
		<< "1 to get a Rhombus:" << endl
		<< "2 to get a hollow Rhombus:" << endl
		<< "3 to get a Rectangle:" << endl
		<< "4 to get a hollow Rectangle:" << endl
		<< "5 to get a Butterfly:" << endl
		<< "6 to get a hollow Butterfly:" << endl
		<< "0 to exit:" << endl;

		cin >> choice;

		bool isdigit = true;
		for (int i = 0; choice[i] != '\0'; i++)
		{
			if (choice[i] < '0' || choice[i] > '9')
			{
				isdigit = false;
				break;
			}
		}
		if (!isdigit)
		{
			cout << "Invalid characters. Please try again!" << endl;
			continue;
		}
		//convert choice to integer

		switch (stoi(choice))
		{
		case 1:
			Rhombus();
			break;
		case 2:
			HollowRhombus();
			break;
		case 3:
			Rectangle();
			break;
		case 4:
			HollowRectangle();
			break;
		case 5:
			Butterfly();
			break;
		case 6:
			HollowButterfly();
			break;
		case 0:
			cout << "You are exited successfully *_^" << endl;
			return 0; //Using return 0; terminates the program immediately, If use break;  the program would print the message but continue running the loop, prompting the user again.
		default:
			cout << "You should input numbers till 6 number not greater" << endl;
		}
	}
	return 0;

}
