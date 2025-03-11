#include <iostream>
using namespace std;

void DrawBoard(char board[6][7])
{
	bool horizontal = true;

	for (int i = 0; i < 13; i++)
	{
		if (horizontal)
		{
			for (int j = 0; j < 7; j++)
			{
				if(i != 0)
					cout << "----";
			}
		}
		else
		{
			for (int j = 0; j < 7; j++)
			{
				cout << "| " << board[i / 2][j] << " ";
			}
			cout << "|";
		}
		cout << endl;
		horizontal = !horizontal;
	}
}
void InitializeBoard(char board[6][7])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			board[i][j] = ' ';
		}
	}
}
char CheckWinner(char board[6][7])
{
	//vertical
	for (int i = 0; i < 7; i++)
	{
		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i])
		{
			return board[0][i];
		}
		if (board[1][i] != ' ' && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[3][i] == board[4][i])
		{
			return board[1][i];
		}
		if (board[2][i] != ' ' && board[2][i] == board[3][i] && board[3][i] == board[4][i] && board[4][i] == board[5][i])
		{
			return board[2][i];
		}
	} 
	//horizontal
	for (int i = 0; i < 6; i++)
	{
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3])
		{
			return board[i][0];
		}
		if (board[i][1] != ' ' && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4])
		{
			return board[i][1];
		}
		if (board[i][2] != ' ' && board[i][2] == board[i][3] && board[i][3] == board[i][4] && board[i][4] == board[i][5])
		{
			return board[i][2];
		}
		if (board[i][3] != ' ' && board[i][3] == board[i][4] && board[i][4] == board[i][5] && board[i][5] == board[i][6])
		{
			return board[i][3];
		}
	}
	//right diagonal
	for (int i = 0; i < 3; i++)
	{
		for (int j = 6; j > 2; j--)
		{
			if (board[i][j] != ' ' && board[i][j] == board[i + 1][j - 1] && 
				board[i + 1][j - 1] == board[i + 2][j - 2] && 
				board[i + 2][j - 2] == board[i + 3][j - 3])
					return board[i][j];
		}
	}
	//left diagonal
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] != ' '&& board[i][j] == board[i + 1][j + 1] && 
				board[i + 1][j + 1] == board[i + 2][j + 2] && 
				board[i + 2][j + 2] == board[i + 3][j + 3])
					return board[i][j];
		}
	}

	return ' ';
}
int lowestlevel(char board[6][7], int j) 
{
    for (int i = 5; i >= 0; i--) 
    {
        if (board[i][j] == ' ') 
        {
            return i;
        }
    }
    return -1;
}

int main() 
{
	char result = ' ';
	char board[6][7];
	InitializeBoard(board);
	DrawBoard(board);

	bool isX = true;
	int countGames = 0;

	while (result == ' ')
	{
		int y;
		cout << "drop your piece: ";

		while (true) 
		{
			cin >> y;
			if (cin.fail() || y < 0 || y >= 7 || lowestlevel(board, y) == -1) 
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid column! try again ";
			}
			else 
			{
				break;
			}
		}

		int x = lowestlevel(board, y);
		if (isX)
		{
			board[x][y] = 'X';
		}
		else
		{
			board[x][y] = 'O';
		}
		countGames++;
		DrawBoard(board);
		result = CheckWinner(board);
		if (result == 'X')
		{
			cout << "Congratulations! X won" << endl;
			break;
		}
		if (result == 'O')
		{
			cout << "Congratulations! O won" << endl;
			break;
		}

		if (countGames == 42) 
		{
			cout << "Game over! It's a tie." << endl;
			break;
		}

		isX = !isX;
	}

	return 0;
}

