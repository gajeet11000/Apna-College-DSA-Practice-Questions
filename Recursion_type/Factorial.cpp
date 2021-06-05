#include <unordered_map>
#include <string>
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

int fact(int number)
{
	if(number < 2)
	{
		return number;
	}

	return number * fact(number-1);
}

int main()
{
	cout << "Enter the number to find the factorial: ";
	int number{};
	cin >> number;

	cout << "\nThe factorial of " << number << " is " << fact(number) << endl;
	return 0;
}

