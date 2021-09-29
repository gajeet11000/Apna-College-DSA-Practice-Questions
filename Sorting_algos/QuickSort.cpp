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

void printArray(int array[], int n)
{
	for(int i=0 ; i<n ; i++)
	{
		cout << array[i] << " ";
	}
}

void swap(int array[], int i, int j)
{
	int swap_temp{};

	swap_temp = array[j];
	array[j] = array[i];
	array[i] = swap_temp;
}


void quickSort(int array[], int start, int end)
{
	if(end - start <= 1)
	{
		return;
	}

	int pivot = start;

	int lower_bound = pivot+1;

	for(int upper_bound = pivot+1 ; upper_bound <= end ; upper_bound++)
	{
		if(array[upper_bound] <= array[pivot])
		{
			swap(array, lower_bound, upper_bound);
			lower_bound++;
		}
	}

	swap(array, pivot, lower_bound-1);

	pivot = lower_bound-1;

	quickSort(array, start, pivot-1);
	quickSort(array, pivot+1, end);
}

int main()
{
	int array[] = {4, 3, 6, 7, 1, 3, 6, 8, 1, 7, 8, 4, 10, 8, 10};
//	int array[] = {23, 35, 2, 55, 12, 23, 54, 12, 90};

	cout << "Given array:-" << endl;
	printArray(array, 15);

	quickSort(array, 0, 15);

	cout << "\nSorted array:-" << endl;
	printArray(array, 15);
	return 0;
}

