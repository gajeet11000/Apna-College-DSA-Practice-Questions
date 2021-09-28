#include <unordered_map>
#include <string>
#include <map>
#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;


bool isSafe(bool** chessboard, int x, int y, int n)
{
	for(int i=x ; i>=0 ; i--)
	{
		if(chessboard[i][y])
		{
			return false;
		}
	}

	int i=x;
	int j=y;

	while(i >= 0 && j >= 0)
	{
		if(chessboard[i][j])
		{
			return false;
		}
		i--;
		j--;
	}

	i=x;
	j=y;

	while(i >= 0 && j<n)
	{
		if(chessboard[i][j])
		{
			return false;
		}
		i--;
		j++;
	}

	return true;
}

bool** createBoard(int n)
{
	bool** board = new bool*[n];
	
	for(int i =0 ; i<n ; i++)
	{
		bool* arr = new bool[n];
		board[i] = arr;
		
		for(int j=0 ; j<n ; j++)
		{
			board[i][j] = false;
		}
	}

	return board;
}


bool nQueen(bool** chessboard, int row, int n)
{
	if(row >= n)
	{
		return true;
	}

	for(int i=0 ; i<n ; i++)
	{
		if(isSafe(chessboard, row, i, n))
		{
			chessboard[row][i] = true;

			if(nQueen(chessboard, row+1, n))
			{
				return true;
			}

			chessboard[row][i]= false;
		}
	}
	return false;
}

void printSolution(bool** v, int n)
{
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	cout << "Enter the number of queens: ";
	int n{};
	cin >> n;

	bool** chessboard = createBoard(n);

	if(nQueen(chessboard, 0, n))
	{
		printSolution(chessboard, n);
	}
	else
	{
		cout << "No Solution Found :(" << endl;
	}


	return 0;
}
