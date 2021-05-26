#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

void printFactorsOf(int number)
{
	for(int i=1 ; i<=(number / 2) ; i++)
	{
		if(number % i == 0)
			cout << i << " ";
	}
	cout << number;
}

int main()
{
	int n;
	cout << "Enter a number to print all it's factors: ";
	cin >> n;

	cout << "Factors of " << n << " are:- " << endl;
	printFactorsOf(n);
	return 0;
}

