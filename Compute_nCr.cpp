#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

int long factorial(int number)
{
	int i{1};
	int long fact{1};

	while(number-- > 0)
	{
		fact *= i;
		i++;
	}
	return fact;
}

double nCr(int n, int r)
{
	return factorial(n)/(factorial(r)*factorial(n - r));
}

int main()
{
	int n, r;
	cout << "Enter n and r to compute n choose k (nCr): ";
	cin >> n >> r;

	cout << n << " choose " << r << " (nCr) is " << nCr(n, r); 
	return 0;
}

