#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

int countRecordBreakingDays(int array[], int length)
{
	int number_of_record_breaking_days{0};
	int maximum_visitors{-1};

	for(int i=0 ; i<length ; i++)
	{
		if(i == 0 && array[i] > array[i+1])
			number_of_record_breaking_days++;

		else if(i == length-1 && array[i] > maximum_visitors)
			number_of_record_breaking_days++;

		else if(array[i] > maximum_visitors && array[i] > array[i+1])
			number_of_record_breaking_days++;

		maximum_visitors = max(maximum_visitors, array[i]);
	}
	return number_of_record_breaking_days;
}

void input(int array[], int length)
{
	cout << "\nEnter the array elements:-" << endl;
	for(int i=0 ; i<length ; i++)
		cin >> array[i];
}

int main()
{
	int t{};
	cout << "Enter the number of test cases: ";
	cin >> t;

	int length{};
	
	for(int i=0 ; i<t ; i++)
	{
		cin >> length;

		int array[length];

		input(array, length);

		cout << "Case #" << i+1 << ": " << countRecordBreakingDays(array, length) << endl;
	}

	return 0;
}

