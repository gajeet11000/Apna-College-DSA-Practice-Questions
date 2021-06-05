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

int fib(int nth)
{
	if(nth < 2)
	{
		return nth;
	}

	return fib(nth-1) + fib(nth-2);
}

int main()
{
	cout << "Enter the nth fibonacci position: ";
	int nth{};
	cin >> nth;

	cout << "\nThe " << nth << " fibonacci number is " << fib(nth) << endl;
	return 0;
}

