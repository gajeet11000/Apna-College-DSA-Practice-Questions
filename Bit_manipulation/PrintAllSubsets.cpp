#include <unordered_map>
#include <map>
#include <string>
#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

void printAllSubsets(int array[], int size)
{
	for(int i=0 ; i<(1<<size) ; i++)
	{
		for(int j=0 ; j<size ; j++)
		{
			if(i & (1 << j))
			{
				cout << array[j] << " ";
			}
		}
		cout << endl;
	}
	return;
}

void input(int array[], int size)
{
	cout << "\nEnter the array elements:-" << endl;
	for(int i=0 ; i<size ; i++)
	{
		cin >> array[i];
	}
}

int main()
{
	cout << "Enter the array size: ";
	int size{};
	cin >> size;

	int array[size]{};

	input(array, size);

	cout << "\nThe subsets are:-" << endl;
	printAllSubsets(array, size);

	return 0;
}

