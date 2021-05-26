// Easy Arrays Maps
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

int firstRepeatingElementUsingArray(int array[], int length)
{
	int checked_elements[(int)1e6];

	int minimum_index{INT_MAX};

	fill_n(checked_elements, 1e6, -1);

	for(int i=0 ; i<length ; i++)
	{
		if(checked_elements[(array[i])] != -1)
		{
			minimum_index = min(minimum_index, checked_elements[array[i]]);
		}
		else
		{
			checked_elements[array[i]] = i;
		}
	}
	return (minimum_index == INT_MAX)? -1 : minimum_index;

}

int firstRepeatingElementUsingMap(int array[], int length)
{
	map<int, int> checked_elements;
	int minimum_index{INT_MAX};

	for(int i=0 ; i<length ; i++)
	{
		if(checked_elements.find(array[i]) != checked_elements.end())
		{
			minimum_index = min(minimum_index, checked_elements[array[i]]);
		}
		else
		{
			checked_elements[array[i]] = i;
		}
	}
	return (minimum_index == INT_MAX)? -1 : minimum_index;
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

	int answer = firstRepeatingElementUsingMap(array, length);

	cout << "\nAnwer using Map:-" << endl;

	if(answer != -1)
	{
		cout << "\nThe index of the first repeating element is "
			 << answer << endl;
		cout << "The repeating element is " << array[answer] << endl;
	}	
	else
	{
		cout << "\nThere are no repeating elements." << endl;
	}

	answer = firstRepeatingElementUsingArray(array, length);

	cout << "\nAnswer using Arrays:-" << endl;

	if(answer != -1)
	{
				cout << "\nThe index of the first repeating element is "
			 << answer << endl;
		cout << "The repeating element is " << array[answer];
	}	
	else
	{
		cout << "\nThere are no repeating elements." << endl;
	}
	return 0;
}

