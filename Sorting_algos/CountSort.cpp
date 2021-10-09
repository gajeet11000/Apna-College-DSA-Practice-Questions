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

void printArray(int* array, int size)
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

int* countSort(int array[], int size)
{
	int max_element{INT_MIN};

	for(int i=0 ; i<size ; i++)
	{
		max_element = max(max_element, array[i]);
	}

	int frequency_array[max_element+1]{};

	for(int i=0 ; i<size ; i++)
	{
		frequency_array[array[i]]++;
	}

	for(int i=1 ; i<max_element+1 ; i++)
	{
		frequency_array[i] += frequency_array[i-1];
	}

	int* sortedArray = new int[size];

	for(int i=0 ; i<size ; i++)
	{
		sortedArray[frequency_array[array[i]]-1] = array[i];
		frequency_array[array[i]]--;
	}

	return sortedArray;
}

int main()
{
	cout << "Enter the size of the array: ";
	int size{};
	cin >> size;

	int array[size]{};

	cout << "\nEnter the array elements:- " << endl;
	inputArray(array, size);

	int* sortedArray = countSort(array, size);

	cout << "\nSorted array:- " << endl;
	printArray(sortedArray, size);

	return 0;
}