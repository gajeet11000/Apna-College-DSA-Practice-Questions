#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

int kadanesAlgorithm(const int array[], int length)
{
	int current_sum{};
	int maximum_sum{INT_MIN};

	for(int i=0 ; i<length ; i++)
	{
		current_sum += array[i];
		if(current_sum < 0)
		{
			current_sum = 0;
		}
		maximum_sum = max(maximum_sum, current_sum);
	}	
	return maximum_sum;
}


int circularSubArraySum(int array[], const int length)
{
	int non_wrap_sum = kadanesAlgorithm(array, length); // When no wrapping is needed.

	int total_array_sum{};

	for(int i=0 ; i<length ; i++)
	{
		total_array_sum += array[i];
		array[i] = -array[i];               // The negatives and positives are switched to find the sum of noncontributing elements.
	}

	int sum_of_non_contributing_elements_in_non_wrap_sum = kadanesAlgorithm(array, length);
	
	int wrap_sum = total_array_sum - (-sum_of_non_contributing_elements_in_non_wrap_sum);

	return max(wrap_sum, non_wrap_sum);
}




void input(int array[], int length)
{
	cout << "Enter the array elements:-" << endl;
	for(int i=0 ; i<length ; i++)
	{
		cin >> array[i];
	}
}

int main()
{
	int length{};
	cout << "Enter the size of the array: ";
	cin >> length;

	int array[length];

	input(array, length);

	cout << "Maximum subarray sum: " << circularSubArraySum(array, length) << endl;
	return 0;
}

