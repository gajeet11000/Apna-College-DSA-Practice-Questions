#include <unordered_map>
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

void traverseArraySpirally(int rows, int columns,const vector<vector<int>> &v)
{
	int top_row{}, bottom_row{rows-1};
	int left_column{}, right_column{columns-1};

	int i{};

	while(top_row <= bottom_row && left_column <= right_column)
	{
		i = left_column;
		while(i <= right_column)
		{
			cout << v[top_row][i] << " ";
			i++;
		}
		top_row++;

		i = top_row;
		while(i <= bottom_row)
		{
			cout << v[i][right_column] << " ";
			i++;
		}
		right_column--;

		i = right_column;
		while(i >= left_column)
		{
			cout << v[bottom_row][i] << " ";
			i--;
		}
		bottom_row--;

		i = bottom_row;
		while(i >= top_row)
		{
			cout << v[i][left_column] << " ";
			i--;
		}
		left_column++;
	}
	return;
}

void input(int rows, int columns, vector<vector<int>> &v)
{
	cout << "Enter the elements of the 2D v:-" << endl;
	
	for(int i=0 ; i<rows ; i++)
	{
		for(int j=0 ; j<columns ; j++)
		{
			cin >> v[i][j];
		}
	}
}


int main()
{
	int rows{}, columns{};
	cout << "Enter the dimensions of 2D v (n & m): ";
	cin >> rows >> columns;

	vector<vector<int>> v(rows, vector<int> (columns));

	input(rows, columns, v);

	traverseArraySpirally(rows, columns, v);

	cout << "Ended" << endl;
	
	return 0;
}

