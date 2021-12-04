#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>

#define ll long long

using namespace std;

// Time Complexity: O(n^2) Brute Force
int largestRectangleArea(int array[], int size)
{
	int current_height{-1}, current_area{-1};
	int max_area{-1};

	for(int i=0, j ; i<size ; i++) //2 1 5 6 2 3
	{
		current_height = array[i];
		current_area = array[i];

		j = i+1;
		while(array[j] >= current_height && j<size)
		{
			current_area += current_height;
			j++;
		}
		cout << current_area << endl;

		max_area = max(max_area, current_area);
	}

	return max_area;
}

int traceBackStack(stack<int> &mystack, int max_area)
{
	int width{1};

	while(!mystack.empty())
	{
		max_area = max(max_area, mystack.top()*width);
		mystack.pop();
		width++;
	}
	return max_area;
}

// Time Complexity: O(n)
int largestRectangleAreaStack(int array[], int size) 
{
	int max_area{};

	stack<int> mystack;

	for(int i=0 ; i<size ; i++)
	{
		if(!mystack.empty() && array[i] < mystack.top())
		{
			max_area = traceBackStack(mystack, max_area);
		}
		mystack.push(array[i]);
	}

	max_area = traceBackStack(mystack, max_area);

	return max_area;
}

void inputArray(int array[], int n)
{
	for(int i=0 ; i<n ; i++)
	{
		cin >> array[i];
	}
}

int main()
{
	cout << "Enter the size of the array: ";
	int size; cin >> size;

	int array[size];

	cout << "\nEnter the array elements:-\n";
	inputArray(array, size);

	cout << "\nMax area rectangle: " << largestRectangleAreaStack(array, size);

}