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

int possiblePaths2DMaze(int maze_size, int x_pos = 0, int y_pos = 0)
{
	if(x_pos == maze_size-1 && y_pos == maze_size-1)
	{
		return 1;
	}
	if(x_pos >= maze_size || y_pos >= maze_size)
	{
		return 0;
	}

	return possiblePaths2DMaze(maze_size, x_pos + 1, y_pos) + 
		   possiblePaths2DMaze(maze_size, x_pos, y_pos+1); 
}

int main()
{
	cout << "Enter the maze size: ";
	int maze_size{};
	cin >> maze_size;

	cout << "\nNumber of all possible paths in maize: "
		 << possiblePaths2DMaze(maze_size);
	return 0;
}

