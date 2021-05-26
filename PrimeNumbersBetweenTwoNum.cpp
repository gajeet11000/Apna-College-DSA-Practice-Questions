#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

bool isPrime(int number)
{
	for(int i=2 ; i<=sqrt(number) ; i++)
	{
		if(number % i == 0)
			return false;
	}
	return true;
}

void PrimeNumbersBetween(int number1, int number2)
{
	while(number1 <= number2)
	{
		if(isPrime(number1))
		{
			cout << number1 << " ";
		}
		number1++;
	}
}

int main()
{
	int n, m;
	cout << "Enter range to find prime numbers between them: ";
	cin >> n >> m;

	cout << "Prime numbers between the range " << n << " and " << m << " are:-\n";
	PrimeNumbersBetween(n , m);
	return 0;
}

