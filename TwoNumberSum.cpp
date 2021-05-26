#include <cctype>
#include <unordered_map>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

void twoNumberSumUsingHashMap(const int array[], int length, int key)
{
	int difference_required{};

	unordered_map<int, bool> encountered_elements;

	for(int i=0 ; i<length ; i++)
	{
		difference_required = key - array[i];
		
		if(encountered_elements.find(difference_required) != encountered_elements.end())
		{
			cout << "\nThe two numbers that sum to " << key << " are ";
			cout << difference_required  << " & " << array[i] << endl;
			return;
		}
		else
		{
			encountered_elements[array[i]] = true;
		}
	}
	cout << "\nNo two number found that sum up to " << key << endl;
}

void twoNumberSumUsingSortingTwoPointerMethod(int array[], int length, int key)
{
	sort(array, array + length);

	int sum{};
	int left_pointer{};
	int right_pointer{length-1};

	while(left_pointer < right_pointer)
	{
		sum = array[left_pointer] + array[right_pointer];

		if(sum == key)
		{
			cout << "\nThe two numbers that sum to " << key << " are ";
			cout << array[left_pointer]  << " & " << array[right_pointer] << endl;
			return;
		}
		else if(sum < key)
		{
			left_pointer++;
		}
		else
		{
			right_pointer--;
		}
	}
	cout << "\nNo two number found that sum up to " << key << endl;
}

void input(int array[], int length)
{
	cout << "\nEnter the array elements:- " << endl;
	for(int i=0 ; i<length ; i++)
	{
		cin >> array[i];
	}
}

int main()
{
	int length{};
	cout << "Enter the size of array: ";
	cin >> length;

	int array[length];

	input(array, length);

	int sum_to_find{};
	cout << "\nEnter the sum to be found: ";
	cin >> sum_to_find;

	cout << "\nUsing HashMap method:-";
	twoNumberSumUsingHashMap(array, length, sum_to_find);

	cout << "\nUsing Sorting Two Pointer method:-";
	twoNumberSumUsingSortingTwoPointerMethod(array, length, sum_to_find);

	return 0;
}

