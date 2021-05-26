#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

void selectionSort(int array[], int n)
{
	int temp{};

	for(int i=0 ; i<n-1 ; i++)
	{
		for(int j=i+1 ; j<n ; j++)
		{
			if(array[j] < array[i])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
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

void input(int array[], int n)
{
	cout << "\nEnter the array to be sorted:-" << endl;
	for(int i=0 ; i<n ; i++)
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

	selectionSort(array, n);

	print(array, n);

	return 0;
}

