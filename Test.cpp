#include <unordered_map>
#include <map>
#include <stdio.h>
#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

int main()
{
	int rows{}, col{};
	cin >> rows >> col;
	int arrays[rows][col];
	
	for(int i=0 ; i<rows ; i++)
	{
		for(int j=0 ; j<col ; j++)
		{
			cin >> arrays[i][j];
		}
	}
	for(int i=0 ; i<rows ; i++)
	{
		for(int j=0 ; j<col ; j++)
		{
			cout << arrays[rows][col] << " ";
		}
		cout << endl;
	}
    return 0;
}

