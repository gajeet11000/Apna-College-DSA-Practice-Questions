#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

int reverse(int input_number)
{
	int reversed_number{};
	int last_digit{};

	while(input_number > 0)
	{
		reversed_number *= 10;
		last_digit = input_number % 10;
		reversed_number += last_digit;
		input_number /= 10;
	}
	return reversed_number;
}

int main()
{
	int n;
	cout << "Enter a number to get it's reverse: ";
	cin >> n;

	cout << "Reverse of " << n << " is " << reverse(n) << endl;
	return 0;
}

