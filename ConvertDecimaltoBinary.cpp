#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>

#define ll long long

using namespace std;

int long convertDecimaltoBinary(int n)
{
	int long binary_number{};
	int long multiplier{1};
	int remainder{};

	while(n > 0)
	{
		remainder = n % 2;
		binary_number += remainder * multiplier;
		multiplier *= 10;
		n /= 2;
	}
	return binary_number;
}

int main()
{
	int n;
	cout << "Enter a decimal number to convert into binary: ";
	cin >> n;
	
	cout << n << " in binary number system is " << convertDecimaltoBinary(n) << endl;
	return 0;
}

