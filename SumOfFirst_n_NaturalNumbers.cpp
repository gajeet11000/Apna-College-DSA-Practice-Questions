#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

int long sumOfnNaturalNumbers(int n)
{
	int i{1};
	int long sum{};
	while(i <= n)
	{
		sum += i;
		i++;
	}
	return sum;
}

int main()
{
	int n;
	cout << "Enter number to sum from 1 to that number: ";
	cin >> n;

	cout << "The total sum from 1 to " << n << " is " << sumOfnNaturalNumbers(n) << "." << endl;
	return 0;
}

