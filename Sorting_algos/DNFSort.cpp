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

void dnfSort(int array[], int size)
{

	int low{}, mid{}, high{size-1};

	while(mid <= high)
	{
		if(array[mid] == 0)
		{
			swap(array, mid, low);
			low++;
			mid++;
		}
		else if(array[mid] == 2)
		{
			swap(array, mid, high);
			high--;
		}
		else
		{
			mid++;
		}
	}
}

int main()
{
	cout << "Enter the size of the array: ";
	int size{};
	cin >> size;

	int array[size]{};

	cout << "\nEnter the array elements (only 0s, 1s, or 2s):-" << endl;
	inputArray(array, size);

	dnfSort(array, size);

	cout << "\nSorted Array:- " << endl;
	printArray(array, size);

	return 0;
}