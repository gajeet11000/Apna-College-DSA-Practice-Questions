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

void printArray(int array[], int size)
{
	for(int i=0 ; i<size ; i++)
	{
		cout << array[i] << " ";
	}
}

void inputArray(int array[], int size)
{
	for(int i=0 ; i<size ; i++)
	{
		cin >> array[i];
	}
}

void swap(int array[], int i, int j)
{
	int temp{array[i]};
	array[i] = array[j];
	array[j] = temp;
}

void waveSort(int array[], int size)
{
	for(int i=1 ; i<size ; i+=2)
	{
		if(array[i] > array[i-1])
		{
			swap(array, i, i-1);
		}

		if(i < size-1 && array[i] > array[i+1])
		{
			swap(array, i, i+1);
		}
	}
}

int main()
{
	cout << "Enter the size of the array: ";
	int size{};
	cin >> size;

	int array[size];

	cout << "\nEnter the array elements:-" << endl;
	inputArray(array, size);

	waveSort(array, size);

	cout << "\nSorted array in the wave form:- "<< endl;
	printArray(array, size);

	return 0;
}