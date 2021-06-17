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

int possiblePaths(int destination, int current_location = 0)
{
	if(current_location > destination) 
	{
		return 0;
	}
	if(current_location == destination)
	{
		return 1;
	}

	int path_count{};

	for(int i=1 ; i<=6 ; i++)
	{
		path_count += possiblePaths(destination, current_location + i);
	}
	return path_count;
	
}

int main()
{
	cout << "Enter the destination position: ";
	int destination{};
	cin >> destination;

	cout << "\nTotal number of possible paths: "
		 << possiblePaths(destination);
	return 0;
}

