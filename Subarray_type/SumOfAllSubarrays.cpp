#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

void sumOfAllSubarrays(const int array[], int length)
{
	int sum{};

	for(int i=0 ; i<length ; i++)
	{
		for(int j=i ; j<length ; j++)
		{
			sum += array[j]; 
			cout << sum << " ";
		}
		cout << endl;
		sum = 0;
	}
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
	cout << "Enter the length of the array:- ";
	cin >> length;

	int array[length];

	input(array, length);

	sumOfAllSubarrays(array, length);
	return 0;
}

