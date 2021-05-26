#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

long factorial(int number)
{
	int i=1;
	long fact = 1;
	while(number-- > 0)
	{
		fact *= i;
		i++;
	}
	return fact;
}

int main()
{
	int n;
	cout << "Enter a number to get it's factorial: ";
	cin >> n;

	cout << "Factorial of " << n << " is " << factorial(n) << endl;
	return 0;
}

