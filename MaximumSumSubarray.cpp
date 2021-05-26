// Easy Arrays SubArrays Famous
#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

int kadanes_algorithm(const int array[], int length)
{
	int current_sum{};
	int max_negative{INT_MIN};
	int max_sum{INT_MIN};

	for(int i=0 ; i<length ; i++)
	{
		if(array[i] < 0)
		{
			max_negative = max(max_negative, array[i]);
		}

		current_sum += array[i];
		if(current_sum < 0)
		{
			current_sum = 0;
		}
		max_sum = max(max_sum, current_sum);
	}
	return (max_sum == 0) ? max_negative : max_sum;
}

void input(int array[], int length)
{
	cout << "\nEnter the array elements:-" << endl;
	for(int i=0 ; i<length ; i++)
	{
		cin >> array[i];
	}
	cout << endl;
}

int main()
{
	int length{};
	cout << "Enter the size of the array: ";
	cin >> length;

	int array[length];

	input(array, length);

	cout << "Kadane's algorithm answer: "; 
	cout << kadanes_algorithm(array, length) << endl;

	return 0;
}

