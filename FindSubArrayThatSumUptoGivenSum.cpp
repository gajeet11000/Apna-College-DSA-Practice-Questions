// Easy Arrays SubArrays
#include <unordered_map>
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

void subarraySumUpto(const int array[], int length, int sum_to_find)
{
	int left_index{}, right_index{};
	int sum{};

	while(right_index < length)
	{
		sum += array[right_index];

		while(sum > sum_to_find && left_index < right_index)
		{
			sum -= array[left_index];
			left_index++;
		}
		
		if(sum == sum_to_find)
		{
			cout << "\nThe range in the array that sum up to "
				 << sum_to_find << " is from "
				 << left_index << " to " << right_index << endl;
			cout << "(0 based indexing) " << endl;
			return;
		}
		right_index++;
	}
	cout << "\nThere is no such subarray that sum upto " << sum_to_find << "." << endl;
	return;

}

void input(int array[], int length)
{
	cout << "\nEnter the array elements:-" << endl;
	for(int i=0 ; i<length ; i++)
	{
		cin >> array[i];
	}
}

int main()
{
	int length{}, sum{};
	cout << "Enter the size of the array: ";
	cin >> length;

	cout << "\nEnter the sum to be found: ";
	cin >> sum;

	int array[length];

	input(array, length);

	subarraySumUpto(array, length, sum);
	return 0;
}

