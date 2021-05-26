#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

int convertOctalToDecimal(int octal_number)
{
	int multiplier{1};
	int decimal_number{};
	int last_digit{};

	while(octal_number > 0)
	{
		last_digit = octal_number % 10;
		decimal_number += last_digit * multiplier;
		multiplier *= 8;
		octal_number /= 10;	
	}
	return decimal_number;
}

int main()
{
	int n;
	cout << "Enter a octal number to convert into decimal: ";
	cin >> n;

	cout << n << " in decimal is " << convertOctalToDecimal(n) << "." << endl;
	return 0;
}

