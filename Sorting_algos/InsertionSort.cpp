#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

void insertionSort(int array[], int length)
{
	int iterator{-1};
	int select{};

	for(int i=1 ; i<length ; i++)
	{
		if(array[i] < array[i-1])
		{
			iterator = i;
			select = array[i];
			while(select < array[--iterator] && iterator > -1)
			{
				array[iterator+1] = array[iterator];
			}
			array[iterator+1] = select;
		}
	}
}

void print(const int array[], int length)
{
	cout << "\nSorted array:-" << endl;
	for(int i=0 ; i<length ; i++)
	{
		cout << array[i] << " ";
	}
}

void input(int array[], int length)
{
	cout << "\nEnter the array to be sorted:-" << endl;
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

	insertionSort(array, n);

	print(array, n);

	return 0;
}

