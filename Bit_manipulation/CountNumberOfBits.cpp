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

int countBits(int number)
{
	int count{};

	while(number) // All number except 0 is true;
	{
		number = number & (number-1);
		count++;
	}
	return count;
}

int main()
{
	cout << "Enter the number: ";
	int number{};
	cin >> number;
	cout << "The number of bits in " << number << " is " << countBits(number) << endl;
	return 0;
}

