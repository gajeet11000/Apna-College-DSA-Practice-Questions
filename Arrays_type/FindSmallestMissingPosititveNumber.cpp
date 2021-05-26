// Easy Arrays
#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

int smallestMissingPositiveNumber(int array[], int length)
{
	bool encountered_positive_numbers[(int)1e6];
	int smallest_positive_number{INT_MAX};

	for(int i=0 ; i<length ; i++)
	{
		if(array[i] > -1)
		{
			encountered_positive_numbers[array[i]] = true;
			smallest_positive_number = min(smallest_positive_number, array[i]);
		}
	}
	
	for(int i=smallest_positive_number ; i<10e6 ; i++)
	{
		if(!encountered_positive_numbers[i])
			return i;
	}
	return -1;
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
	int length{};
	cout << "Enter the size of the array: ";
	cin >> length;

	int array[length];

	input(array, length);

	int answer = smallestMissingPositiveNumber(array, length);
	
	if(answer != -1)
	{
		cout << "\nThe smallest missing positive number in the array is: ";
		cout << answer << endl;
	}
	else
	{
		cout << "\nThere is no such element in the array." << endl;
	}
	
	return 0;
}

