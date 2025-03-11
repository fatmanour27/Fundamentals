#include <iostream>
#include <string>
using namespace std;
/*

     ---- ---- ----    --> first level horizontal, then flip by making horizontal = !horizontal to flip to vertical and so on.
	 |   |    |    |   --> second level vertical
	 ---- ---- ----    --> third level horizontal
	 |   |    |    |   --> fourth level vertical
	 ---- ---- ----    --> fifth level horizontal
	 |   |    |    |   --> sixth level vertical
	 ---- ---- ----    --> seventh level horizontal

	 this board has 9 blocks,  3 raw x 3 column so this blocks represented as 2 dimensional array as 3 x 3
*/
void DrawBoard(char board[3][3])
{
	bool horizontal = true;

	for (int i = 0; i < 7; i++)  //7 levels, 4 level for horizontal, 3 levels for vertical
	{
		if (horizontal)
		{
			for (int j = 0; j < 3; j++) //the 3 levels for vertical, each vertical level contain 3 blocks for 4 vertical columns
			{
				cout << "----";
			}
		}
		else
		{
			for (int j = 0; j < 3; j++)
			{
				cout << "| " << board[i / 2][j] << " ";
			}
			cout << "|";
		}
		cout << endl;
		horizontal = !horizontal;
	}
}
void InitializeBoard(char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}
char CheckWinner(char board[3][3])
{
	
	//left diagonal
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	//right diagonal
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}
	//horizontal
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//vertical
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	return ' ';
}

void Validate(int& a, int& b)  //we must call value a and b by reference to update them in main function with x, y value
{
	while ((a < 0 || a > 2) || (b < 0 || b > 2))
	{
		cout << "The indexing out of range. Please try again" << endl;
		cin >> a;
		cin >> b;
	}
	
}

int main()
{

	char result = ' ';
	char board[3][3]; 
	InitializeBoard(board);
	DrawBoard(board);

	bool isX = true;
	int CountGames = 0;

	while (result == ' ')
	{
		int x, y;
		string xs, ys;

		cout << "Choose your board block: ";
		cin >> x >> y;
		Validate(x, y);
	
		while(board[x][y] != ' ')
		{
			cout << "This block is filled already. Please try again!" << endl;
			cin >> x >> y;
		}
		
		if (isX)
		{
			board[x][y] = 'X';
		}
		else
		{
			board[x][y] = 'O';
		}

		CountGames++;
		DrawBoard(board);
		result = CheckWinner(board);

		if (result == ' ' && CountGames == 9)
		{
			cout << "Game over !"<<endl;
			break;
		}

		isX = !isX;
		if (result == 'X')
		{
			cout << "congratulation! X won" << endl;
		}
		else if (result == 'O')
		{
			cout << "congratulation! O won" << endl;
		}
	}
	

	return 0;
}