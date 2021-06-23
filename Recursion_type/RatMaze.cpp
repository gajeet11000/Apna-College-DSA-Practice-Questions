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

bool isValidMove(vector<vector<char>> maze, int i, int j)
{
	int row = maze.size();
	int col = maze[0].size();

	return i<row && j<col && maze[i][j] != 'W';
}

bool findPath(vector<vector<char>> maze, char** maze_solution, int i = 0, int j = 0)
{
	int row = maze.size();
	int col = maze[0].size();

	if(!isValidMove(maze, i, j))
	{
		return false;
	}

	maze_solution[i][j] = '*';
	
	if(i == row-1 && j == col-1)
	{
		return true;
	}

	if(!findPath(maze, maze_solution, i, j+1))
	{

		if(!findPath(maze, maze_solution, i+1, j))
		{
			maze_solution[i][j] = '.';
			return false;
		}
		else
			return true;
	}	
	else
		return true;
}

char** createEmptyMazeSolution(int rows, int cols)
{
	char** empty_maze_solution = new char*[rows];

	for(int i=0 ; i<rows ; i++)
	{
		char* arr = new char[cols];
		empty_maze_solution[i] = arr;

		for(int j=0 ; j<cols ; j++)
		{
			empty_maze_solution[i][j] = '.';
		}
	}
	return empty_maze_solution;
}

void printSolutionPath(char** maze_solution, int rows, int cols)
{
	cout << "Maze solution:-\n" << endl;

	for(int i=0 ; i<rows ; i++)
	{
		for(int j=0 ; j<cols ; j++)
		{
			cout << maze_solution[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	vector<vector<char>> maze = 
	{
		{'.', 'W', 'W', 'W', 'W'},
		{'.', 'W', '.', '.', '.'},
		{'.', '.', '.', 'W', 'W'},
		{'.', 'W', '.', '.', '.'},
		{'.', '.', '.', 'W', '.'},
		{'.', 'W', '.', 'W', '.'}
	};

	int rows = maze.size();
	int cols = maze[0].size();

	char** maze_solution = createEmptyMazeSolution(rows, cols);

	if(findPath(maze, maze_solution))
	{
		printSolutionPath(maze_solution, rows, cols);
		cout << "\nSolution Found!" << endl;
	}
	else
	{
		cout << "No Solution Found!" << endl;
	}

	return 0;
}
