#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>

#define ll long long

using namespace std;

int convertBinarytoDecimal(long n)
{
	int last_digit{};
	int decimal_number{};
	int multiplier{1};

	while(n > 0)
	{
		last_digit = n % 10;
		decimal_number += multiplier * last_digit;
		multiplier *= 2;
		n /= 10;
	}
	return decimal_number;
}

int main()
{
	long n;
	cout << "Enter a binary number to convert into decimal: ";
	cin >> n;

	cout << n << " in decimal number system is " << convertBinarytoDecimal(n) << endl;
	return 0;
}

