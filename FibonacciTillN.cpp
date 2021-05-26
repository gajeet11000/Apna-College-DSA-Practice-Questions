#include <cmath>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>

#define ll long long

using namespace std;

void printFibonacciTill(int n)
{
	int first{};
	int second{1};
	int temp{};

	cout << "\n" << first << " " << second << " ";
	while(n-- > 0)
	{
		temp = first + second;
		cout << temp << " ";
		first = second;
		second = temp;
	}
}

int main()
{
	int n;
	cout << "Print Fibonacci series till? --> "; 
	cin >> n;

	printFibonacciTill(n);
	return 0;
}

