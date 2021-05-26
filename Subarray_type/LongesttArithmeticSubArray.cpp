/*Problem
An arithmetic array is an array that contains at least two integers and the differences between consecutive integers are equal. For example, [9, 10], [3, 3, 3], and [9, 7, 5, 3] are arithmetic arrays, while [1, 3, 3, 7], [2, 1, 2], and [1, 2, 4] are not arithmetic arrays.

Sarasvati has an array of N non-negative integers. The i-th integer of the array is Ai. She wants to choose a contiguous arithmetic subarray from her array that has the maximum length. Please help her to determine the length of the longest contiguous arithmetic subarray.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the integer N. The second line contains N integers. The i-th integer is Ai.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the length of the longest contiguous arithmetic subarray.
Limits

Time limit: 20 seconds per test set.

Memory limit: 1GB.
1 ≤ T ≤ 100.
0 ≤ Ai ≤ 109.
Test Set 1

2 ≤ N ≤ 2000.
Test Set 2

2 ≤ N ≤ 2 × 105 for at most 10 test cases.
For the remaining cases, 2 ≤ N ≤ 2000.

Sample

Input

4                   -:Test cases

7					-:No. of elements
10 7 4 6 8 10 11    -:Elements

4	
9 7 5 3				

9
5 5 4 5 5 5 4 5 6

10
5 4 3 2 1 2 3 4 5 6

*/


#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

int longestArithmeticSubArray(ll array[], int length)
{
	int longest{2};
	int current_longest{2};
	int difference{};

	difference = array[0] - array[1];

	for(int i=1 ; i<length-1 ; i++)
	{

		if(difference != array[i] - array[i+1])
		{
			difference = array[i] - array[i+1];
			current_longest = 2;
		}
		else
		{
			current_longest++;
		}

		longest = max(longest, current_longest);
	}
	return longest;
}

void input(ll array[], int length)
{
	cout << "Enter the elements of the array:- " << endl;
	for(int i=0 ; i<length ; i++)
	{
		cin >> array[i];
	}
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

		ll array[length];

		input(array, length);

		cout << "Case #" << i+1 << ": " << longestArithmeticSubArray(array, length) << endl;
	}

	return 0;
}

