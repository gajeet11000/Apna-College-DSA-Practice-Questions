#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

void bubbleSort(int array[], int length)
{
	int temp{};

	for(int i=0 ; i<length ; i++)
	{
		for(int j=0 ; j<length -i-1 ; j++)
		{
			if(array[j+1] < array[j])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
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

	bubbleSort(array, n);

	print(array, n);

	return 0;
}

