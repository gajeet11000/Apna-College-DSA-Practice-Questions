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

vector<int> searchSortedMatrix(vector<vector<int>> &matrix, int key)
{
	int rows{(int)matrix.size()};
	int columns{(int)matrix[0].size()};

	int i{0};
	int j{columns-1};

	vector<int> result;

	while(i < rows && j < columns)
	{
		if(matrix[i][j] == key)
		{
			result.push_back(i);
			result.push_back(j);
			return result;
		}
		else if(key < matrix[i][j])
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	result.push_back(-1);
	return result;
}

void input(int rows, int columns, vector<vector<int>> &matrix)
{
	cout << "Enter the matrix elements:-" << endl;

	for(int i=0 ; i<rows ; i++)
	{
		for(int j=0 ; j<columns ; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

int main()
{
	cout << "Enter the dimensions for the matrix (n & m): ";
	int rows{}, columns{};
	cin >> rows >> columns;

	vector<vector<int>> matrix(rows, vector<int> (columns));

	input(rows, columns, matrix);

	int key{};
	cout << "\nEnter the element to find: ";
	cin >> key;

	vector<int> result = searchSortedMatrix(matrix, key);

	if(result[0] != -1)
	{
		cout << "\nThe element was found at index: ["
			 << result[0] << ", " << result[1] << "]" << endl;
		cout << "(Zero based indexing)" << endl;
	}
	else
	{
		cout << "\nThe element was not found :(" << endl;
	}

	return 0;
}
