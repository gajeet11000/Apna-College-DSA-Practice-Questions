#include <unordered_map>
#include <map>
#include <string>
#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

/* Program to find the unique number in an array,
 * where all the number except one, are present twice.
 */

int findUniqueNumber(int array[], int size)
{
	int xor_sum{};

	for(int i=0 ; i<size ; i++)
	{
		xor_sum = xor_sum ^ array[i];
	}

	return xor_sum;
}

void input(int array[], int size)
{
	cout << "\nEnter the array elements:-" << endl;

	for(int i=0 ; i<size ; i++)
	{
		cin >> array[i];
	}
}

int main()
{
	int size{};
	cout << "Enter the array size: ";
	cin >> size;

	int array[size]{};

	input(array, size);

	cout << "\nThe unique number is " << findUniqueNumber(array, size) << endl;

	return 0;
}

