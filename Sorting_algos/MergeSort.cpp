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

void print(int array[], int start, int end)
{
	while(start < end)
	{
		cout << array[start] << " ";
		start++;
	}
	cout << endl;
}

void merge(int array[], int start, int middle, int end)
{
	int n1 = middle - start + 1;
	int n2 = end - middle;

	int temp1[n1]{};
	int temp2[n2]{}; // created two temp arrays for first and second half to be merged.


	// populating temp arrays with the respected halfs
	for(int i=0 ; i < n1 ; i++)
	{
		temp1[i] = array[start + i];
	}
	for(int i=0 ; i < n2 ; i++)
	{
		temp2[i] = array[middle+1 + i];
	}

	// merging two temp arrays

	int i=0, j=0, k=start;

	while(i < n1 && j < n2)
	{
		if(temp1[i] < temp2[j])
		{
			array[k++] = temp1[i++];
		}
		else
		{
			array[k++] = temp2[j++];
		}
	}

	// Inserting remaining elements, if any.
	while(i < n1)
	{
		array[k++] = temp1[i++];
	}

	while(j < n2)
	{
		array[k++] = temp2[j++];
	}
}

void mergeSort(int array[], int start, int end)
{
	if(start < end)
	{
		int middle = (start + end)/2;

		mergeSort(array, start, middle);
		mergeSort(array, middle+1, end);

		merge(array, start, middle, end);
	}
}

int main()
{
	int array[] = {4, 3, 6, 7, 1, 3, 6, 8, 1, 7, 8, 4, 10, 8, 10};

	cout << "Given array:-" << endl;
	print(array, 0, 14);

	mergeSort(array, 0, 14);

	cout << "\nSorted array:-" << endl;
	print(array, 0, 15);
}