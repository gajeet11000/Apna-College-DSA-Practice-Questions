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


int firstIndex(int array[], int size, int key)
{
	if(size == 0)
	{
		return -1;
	}

	if(array[0] == key)
	{
		return 0;
	}

	int check = firstIndex(array+1, size-1, key);

	if(check != -1)
	{
		return check+1;
	}
	else
	{
		return check;
	}
}

int lastIndex(int array[], int size, int key)
{
	if(size == 0)
	{
		return -1;
	}

	int check = lastIndex(array+1, size-1, key);

	if(check != -1)
	{
		return check+1;
	}
	if(array[0] == key)
	{
		return 0;
	}
	return check;

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
	cout << "Enter the size of the array: ";
	int size{};
	cin >> size;

	int array[size]{};

	input(array, size);

	cout << "\nNumber to find it's occurances: ";
	int key{};
	cin >> key;

	cout << "\nThe first index of " << key << " is " << firstIndex(array, size, key)
		 << endl;

	cout << "\nThe last index of " << key << " is " << lastIndex(array, size, key)
		 << endl;
	return 0;
}

