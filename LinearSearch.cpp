#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

int linearSearch(int array[], int length, int key)
{
	for(int i=0 ; i<length ; i++)
	{
		if(array[i] == key)
			return i;
	}
	return -1;
}

void input(int array[], int length)
{
	cout << "\nEnter the array:-" << endl;
	for(int i=0 ; i<length ; i++)
	{
		cin >> array[i];
	}
}

int main()
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	int array[n];

	input(array, n);

	int key;
	cout << "\nEnter the element you wanna find: ";
	cin >> key;

	int result{-1};

	if((result = linearSearch(array, n , key)) != -1)
	{
		cout << "\nThe element " << key << " is found at index " << result << endl;
	}
	else
	{
		cout << "\nThe element " << key << " was not found." << endl;
	}
	return 0;
}
