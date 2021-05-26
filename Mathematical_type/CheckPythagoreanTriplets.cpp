#include <cctype>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

bool arePythagoreanTriplets(int a, int b, int c)
{
	int mx = max(max(a, b), c);
	bool result{false};

	if(mx == a && (b*b + c*c) == a*a)
	{
		result = true;
	}
	else if(mx == b && (a*a + c*c) == b*b)
	{
		result = true;
	}
	else if(mx == c && (b*b + a*a) == c*c)
	{
		result = true;
	}

	return result;

}

int main()
{
	int a, b, c;
	cout << "Enter three intergers to check if they are pythagorean triplets: ";
	cin >> a >> b >> c;

	if(arePythagoreanTriplets(a, b, c))
	{
		cout << a << ", " << b << ", " << "and " << c << " are pythagorean triplets." << endl; 
	}
	else
	{
		cout << a << ", " << b << ", " << "and " << c << " are not pythagorean triplets." << endl; 
	}
	return 0;
}

