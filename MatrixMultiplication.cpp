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

vector<vector<int>> matrixMultiplication(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2)
{
	long unsigned int rows{matrix1.size()}, columns{matrix2[0].size()};


	vector<vector<int>> resultant_matrix(rows, vector<int> (columns));

	for(unsigned int i=0 ; i<rows ; i++)
	{
		for(unsigned int j=0; j<columns ; j++)
		{
			for(unsigned int k=0 ; k<matrix2.size() ; k++)
			{
				resultant_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	return resultant_matrix;

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

int main()
{
	int rows{}, columns{};
	cout << "Enter the dimensions for the 1'st matrix (n and m): ";
	cin >> rows >> columns;

	vector<vector<int>> matrix1(rows, vector<int> (columns));

	input(rows, columns, matrix1);

	cout << "\nEnter the dimensions for the 2'st matrix (n and m): ";
	cin >> rows >> columns;

	vector<vector<int>> matrix2(rows, vector<int> (columns));

	input(rows, columns, matrix2);


	cout << "\nThe resultant matrix after multiplication:-" << endl;
	print(matrixMultiplication(matrix1, matrix2));
	

	return 0;
}

