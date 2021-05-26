#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

#define ll long long

using namespace std;

int giveAscii(char ch)
{
	return (int)(ch);
}

int main()
{
	char ch;
	cout << "Enter a character to get it's ASCII: ";
	cin >> ch;
	cout << "ASCII code of " << ch << " is " << giveAscii(ch) << endl;
	return 0;
}

