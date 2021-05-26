#include <cmath>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>

#define ll long long

using namespace std;

bool isArmstrong(int n)
{
	int armstrong_sum{};
	int last_digit{};
	int original{n};

	while(n > 0)
	{
		last_digit = n % 10;
		armstrong_sum += pow(last_digit, 3);
		n /= 10;
	}
	return (armstrong_sum == original)? true : false;
}

int main()
{
	int n;
	cout << "Enter a number to check if it is an Armstrong number: ";
	cin >> n;

	if(isArmstrong(n))
	{
		cout << n << " is an Armstrong number." << endl;
	}
	else
	{
		cout << n << " is not an Armstrong number. " << endl;
	}
	return 0;
}

