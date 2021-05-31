#include <unordered_map>
#include <map>
#include <string>
#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

int euclideanGCD(int a, int b)
{
	int remainder{};

	while(b > 0)
	{
		remainder = a % b;
		a = b;
		b = remainder;
	}	
	return a;
}

int main()
{
	cout << "Enter two numbers to find their GCD: ";
	int a{}, b{};
	cin >> a >> b;

	cout << "GCD of " << a << " and " << b << " is " << euclideanGCD(a, b) << endl;

	return 0;
}

