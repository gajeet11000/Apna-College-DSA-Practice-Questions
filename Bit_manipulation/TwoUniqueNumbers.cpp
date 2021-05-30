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

int getBit(int n, int pos)
{
	return (n & (1 << pos))==0;
}

void twoUniqueNumbers(int array[], int size)
{
	int xor_sum{};
	
	for(int i=0 ; i<size ; i++)
	{
		xor_sum = xor_sum ^ array[i];
	}

	int rightmost_bit_index{};
	int xorsum_temp{xor_sum};
	
	while(!(xorsum_temp % 2))
	{
		xorsum_temp /= 2;
		rightmost_bit_index++;
	}
	xorsum_temp = xor_sum;
	
	for(int i=0 ; i<size ; i++)
	{
		if(getBit(array[i], rightmost_bit_index))
		{
			xor_sum = xor_sum ^ array[i];
		}
	}

	cout << xor_sum << " " << (xorsum_temp ^ xor_sum);
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
	cout<< "Enter the array size: ";
	cin >> size;
	
	int array[size]{};

	input(array, size);

	cout << "\nThe two unique numbers are: ";
	twoUniqueNumbers(array, size);
	return 0;
}
