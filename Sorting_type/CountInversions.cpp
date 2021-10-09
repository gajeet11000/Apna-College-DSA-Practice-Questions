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

void inputArray(int array[], int size)
{
	for(int i=0 ; i<size ; i++)
	{
		cin >> array[i];
	}
}

ll merge(int array[], int left, int middle, int right)
{
	int n1 = middle - left + 1;
	int n2 = right - middle;

	int left_array[n1]{};
	int right_array[n2]{};

	for(int i=0 ; i<n1 ; i++)
	{
		left_array[i] = array[left + i];
	}

	for(int i=0 ; i<n2 ; i++)
	{
		right_array[i] = array[middle+1 + i];
	}

	int count{};

	int i{}, j{}, k{left};

	while(i<n1 && j<n2)
	{
		if(left_array[i] < right_array[j])
		{
			array[k++] = left_array[i++];
		}
		else
		{
			count += n1 - i;    // Count Inversion Implementation
			array[k++] = right_array[j++];
		}
	}

	while(i < n1)
	{
		array[k++] = left_array[i++];
	}

	while(j < n2)
	{
		array[k++] = right_array[j++];
	}

	return count;
}

ll mergeSort(int array[], int left, int right)
{
	ll inversions{};

	if(left < right)
	{
		int middle = (left + right)/2;

		inversions += mergeSort(array, left, middle);
		inversions += mergeSort(array, middle+1, right);

		inversions += merge(array, left, middle, right);
	}

	return inversions;
}

int main()
{
	cout << "Enter the size of the array: ";
	int size{};
	cin >> size;

	int array[size]{};

	cout << "\nEnter the array elements:- " << endl;
	inputArray(array, size);

	ll inversions = mergeSort(array, 0, size-1);

	cout << "\nNumber of inversions: " << inversions << endl;

	return 0;
}