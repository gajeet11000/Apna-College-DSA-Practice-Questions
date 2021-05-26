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

vector<vector<int>> transposeOfMatrix(vector<vector<int>> &matrix)
{
	int rows = (int) matrix.size();
	int columns = (int) matrix[0].size();

	vector<vector<int>> transpose_matrix;

	for(int i=0 ; i<rows ; i++)
	{
		transpose_matrix.push_back(vector<int>());
		for(int j=0 ; j<columns ; j++)
		{
			transpose_matrix[i].push_back(matrix[j][i]);
		}
	}
	return transpose_matrix;
}

void print(const vector<vector<int>> &matrix)
{
	for(unsigned int i=0 ; i<matrix.size() ; i++)
	{
		for(unsigned int j=0 ; j<matrix[0].size() ; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void input(int rows, int columns, vector<vector<int>> &matrix)
{
	cout << "\nEnter the matrix elements:-" << endl;

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

	cout << "\nTranspose of matrix:-" << endl;
	print(transposeOfMatrix(matrix));

	return 0;
}

