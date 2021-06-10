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

string appendXAtLast(string str)
{
	if(str.empty())
	{
		return str;
	}
	if(str[0] == 'x')
	{
		return appendXAtLast(str.substr(1)) + str[0];
	}
	else
	{
		return str[0] + appendXAtLast(str.substr(1));
	}
}

int main()
{
	cout << "Enter a string containing multiple 'x': ";
	string str{""};
	cin >> str;

	cout << "\nNew string with all 'x' at end: " << appendXAtLast(str) << endl;
	return 0;
}

