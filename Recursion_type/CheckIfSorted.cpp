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

bool isSorted(int array[], int size)
{
	if(size == 1)
	{
		return true;
	}

	if(array[0] <= array[1])
	{
		return isSorted(array+1, size-1);
	}
	else
	{
		return false;
	}
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
	int size{};
	cout << "Enter the size of the array: ";
	cin >> size;

	int array[size];

	input(array, size);

	cout << endl;

	if(isSorted(array, size))
	{
		cout << "The entered array is sorted." << endl;
	}
	else
	{
		cout << "The entered array is not sorted." << endl;
	}
	
	return 0;
}

