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

int rows{};
int cols{};
char** walked_path{NULL};
char** maze_solution{NULL};

bool isValidMove(vector<vector<char>> maze, int i, int j)
{
	return i > -1 && j > -1 && i<rows && j<cols && walked_path[i][j] != '*' && maze[i][j] != 'W';
}

bool findPath(vector<vector<char>> maze, int i = 0, int j = 0)
{
	if(!isValidMove(maze, i, j))
	{
		return false;
	}

	maze_solution[i][j] = '*';
	walked_path[i][j] = '*';
	
	if(i == rows-1 && j == cols-1)
	{
		return true;
	}

	if(findPath(maze, i, j+1) || findPath(maze, i+1, j) || findPath(maze, i-1, j) || 
	   findPath(maze, i, j-1))
	{
		return true;
	}
	else
	{
		maze_solution[i][j] = '.';
		return false;
	}
}

char** createEmptyMazeSolution()
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

void printPath(char** maze_solution, string message)
{
	cout << message << "\n" << endl;

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
		{'.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', 'W'},
		{'.', 'W', 'W', '.', 'W', '.'},
		{'.', '.', '.', 'W', '.', '.'},
		{'.', '.', '.', '.', '.', 'W'},
		{'.', '.', '.', 'W', '.', '.'}
	};

	rows = maze.size();
	cols = maze[0].size();

	maze_solution = createEmptyMazeSolution();
	walked_path = createEmptyMazeSolution();

	if(findPath(maze))
	{
		printPath(maze_solution, "Solution Path:-");
		cout << endl;
		printPath(walked_path, "Walked Path:-");
		cout << "\nSolution Found!" << endl;
	}
	else
	{
		cout << "No Solution Found!" << endl;
	}

	return 0;
}

