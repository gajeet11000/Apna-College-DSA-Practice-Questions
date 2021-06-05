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

int aToPowerB(int base, int power)
{
	if(power == 0)
		return 1;

	return base * aToPowerB(base, power-1);
}

int main()
{
	int base{}, power{};
	cout << "Enter the base and the power: ";
	cin >> base >> power;

	cout << "\n" << base << " to the power " << power << " is " << aToPowerB(base, power) << endl;
	return 0;
}

