#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

int findMaximumTill(const int array[], int I)
{
	int maximum{INT_MIN};

	for(int i=0 ; i<=I ; i++)
	{
		maximum = max(maximum, array[i]);
	}
	return maximum;
}

void input(int array[], int length)
{
	cout << "\nEnter the array elements:-" << endl;
	for(int i=0 ; i<length ; i++)
	   cin >> array[i];	
}

int main()
{
	int length{};
	cout << "Enter the length of the array: ";
	cin >> length;

	int array[length];

	input(array, length);

	int index{-1};
	while(true)
	{
		cout << "\n\nTill what index would you like to find the maximum(for exit -1): ";
		cin >> index;
		if(index == -1)
			break;

		cout << "The maximum element till the index " << index << " is " << findMaximumTill(array, index);
	}
	return 0;
}

