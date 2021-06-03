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

int sumTilln(int number)
{
	if(number == 0)
		return 0;
	
	return number + sumTilln(number - 1); 
}

int main()
{
	int number{};
	cout << "Enter the limit number: ";
	cin >> number;

	cout << "The sum till " << number  << " is " << sumTilln(number);
	return 0;
}

